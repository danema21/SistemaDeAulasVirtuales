#define RESET   "\033[0m"
#define GREEN   "\033[32m"      /* Green */
#define RED     "\033[31m"      /* Red */
#define ORANGE	"\033[33m"		/* orange */
#define BLUE	"\033[34m"		/* blue */

//Fabrica
#include "Fabrica.h"

//Interfaces
#include "ICAltaUsuario.h"
#include "ICAltaAsignatura.h"
#include "ICAsistenciaAClaseEnVivo.h"
#include "ICAsignarAsignaturaDocente.h"
#include "ICEliminarAsignatura.h"
#include "ICInscripcionAsignatura.h"
#include "ICInicioClase.h"
#include "ICEnvioDeMensaje.h"
#include "ICListadoClases.h"

// DT's
#include "DtPerfil.h"
#include "DtAsignatura.h"
#include "DtAsistir.h"
#include "DtTimeStamp.h"
#include "DtIniciarClase.h"
#include "DtIniciarMonitoreo.h"
#include "DtInfoClase.h"
#include "DtInfoMonitoreo.h"
#include "DtParticipacion.h"
#include "DtInfoTeorico.h"

#include <iostream>
#include <list>


Fabrica* fab;
ICAltaUsuario* icaltausuario;
ICAltaAsignatura* icalta_asignatura;
ICAsignarAsignaturaDocente* icasig_docente;
ICInicioClase* icinicioclase;
ICAsistenciaAClaseEnVivo* icasistenciaaclaseenvivo;
ICEliminarAsignatura * iceliminar_asignatura;
ICInscripcionAsignatura* icinscripcionasignatura;
ICEnvioDeMensaje* icenvio_mensaje;
ICListadoClases* iclistado_clases;

using namespace std;

void menu(){
    cout << "Seleccione una opcion:" << endl;
    cout <<GREEN<< "1 ➢ Alta de usuario" <<RESET<< endl;
    cout <<GREEN<< "2 ➢ Alta de asignatura"<<RESET << endl;
    cout <<GREEN<< "3 ➢ Asignacion de docentes a una asignatura:"<<RESET << endl;
    cout <<GREEN<< "4 ➢ Inscripcion a las asignaturas"<<RESET << endl;
    cout <<GREEN<< "5 ➢ Inicio de clase"<<RESET << endl;
    cout <<GREEN<< "6 ➢ Asistencia a clase en vivo" <<RESET<< endl;
    cout <<GREEN<< "7 ➢ Envio de mensaje" <<RESET<< endl;
    cout <<GREEN<< "8 ➢ Eliminacion de asignatura"<<RESET << endl;
    cout <<GREEN<< "9 ➢ Listado de Clases" << endl;
    cout <<GREEN<< "10 ➢ Cargar datos." <<RESET<< endl;
    cout <<GREEN<< "11 ➢ Salir" <<RESET<< endl;
}
// 1 ALTA USUARIO
void menuAltaUsuario(){
	bool seguirIngresandoUsuario = true;

	string nombre;
	string imagen_url;
	string email;
	string password;
	TipoPerfil tipoPerfil;
	string doc;
	string inst;

	while(seguirIngresandoUsuario){
		cout << "Ingrese su nombre: ";
		cin >> nombre;

		cout << "Ingrese el URL de su imagen: ";
		cin >> imagen_url;

		cout << "Ingrese su email: ";
		cin >> email;

		while(icaltausuario->existeUsuario(email)){
			cout << "Email ya ingresado, coloque otro email: ";
			cin >> email;
		}
		
		cout << "Ingrese su password: ";
		cin >> password;
		
		DtPerfil* datosperfil = new DtPerfil(nombre, imagen_url, email, password);
		icaltausuario->ingresarDatosPerfil(datosperfil);

		cout << "Usted es un estudiante o docente? (0 es estudiante, 1 es docente)" << endl;
		int opcionTipoPerfil;
		bool terminarTipoPerfil = false;
		
		while(!terminarTipoPerfil){
			cin >> opcionTipoPerfil;
            switch(opcionTipoPerfil){
				case 0: tipoPerfil = ESTUDIANTE;
						terminarTipoPerfil = true;
						cout << "Ingrese su documento: ";
						cin >> doc;
						icaltausuario->ingresarEstudiante(doc);
						break;
				case 1: tipoPerfil = DOCENTE;
						terminarTipoPerfil = true;
						cout << "Ingrese su instituto: ";
						cin >> inst;
						icaltausuario->ingresarDocente(inst);
						break;
				default: cout << "Opcion invalida." << endl;
						break;
			}
		}
		cout << "Desea confirmar el ingreso? (0 para confirmar, 1 para cancelar)" << endl;
		int opcionUsuario;
		cin >> opcionUsuario;
		
		if(opcionUsuario==0){
		    icaltausuario->altaUsuario();
            cout << "Usuario creado con exito." << endl;
        } else {
			icaltausuario->cancelar();
		}

		cout << "Desea seguir agregando usuarios? (0 para seguir agregando, cualquier otro numero para cancelar)" << endl;
		int opcionSeguirAgregando;
		cin >> opcionSeguirAgregando;

		if(opcionSeguirAgregando != 0){
			seguirIngresandoUsuario = false;
		}
	}
}

// 2 ALTA ASIGNATURA
void menuAltaAsignatura(){
	string nombre;
	string codigo;
	bool teorico = false;
	bool practico = false;
	bool monitoreo = false;
	

	cout << "Ingrese el nombre de la Asignatura: ";
	cin >> nombre;

	cout << "Ingrese el codigo de la Asignatura: ";
	cin >> codigo;
	while(icalta_asignatura->existeAsignatura(codigo)){
		cout << "Ya existe una asignatura con ese codigo." << endl;
		cin >> codigo;
	}

	bool seguirAsignandoTipoClase = true;
	int opcionTipoClase;
	bool unTipoAsignado = false;

	while(seguirAsignandoTipoClase){
		cout << "Ingrese los tipos de clase para la Asignatura (1 teorico, 2 practico, 3 monitoreo)" << endl;
		cin >> opcionTipoClase;
		switch (opcionTipoClase){
		case 1:	teorico = true;
				unTipoAsignado = true;
				cout<< "Teoricos habilitados."<<endl;
				break;
		case 2:	practico = true;
				unTipoAsignado = true;
				cout<< "Practico habilitados."<<endl;
				break;
		case 3:	monitoreo = true;
				unTipoAsignado = true;
				cout<< "Monitoreo habilitados."<<endl;
				break;
		default: cout<< "Opcion incorrecta."<<endl;
				break;
		}
		
		if(unTipoAsignado){
			cout << "Quiere seguir asignando tipos de clase? (1 si, 2 no)"<< endl;
			int continua;
			cin >> continua;

			if(continua==2){
				seguirAsignandoTipoClase=false;
			}
		}else{
			cout << "No ha asignado ningun tipo de clase." << endl;
		}
		
	}

	DtInstanciaClase* dtic = new DtInstanciaClase(teorico, practico, monitoreo);
	DtAsignatura* dta = new DtAsignatura(nombre, codigo, dtic);
	icalta_asignatura->ingresar(dta);

	cout << *dta << endl;
	int opcionAsignatura;

	cout << "Desea dar de alta la Asignatura ingresada? (1 para si, cualquier otro numero para no)" << endl;
	cin >> opcionAsignatura;

	if(opcionAsignatura==1){
		icalta_asignatura->altaAsignatura();
		cout << "Se ingreso con exito la asignatura." << endl;
	} else{
		icalta_asignatura->cancelar();
		cout << "Se libero la memoria asignada a la Asignatura." << endl;
	}
	 
}




// 3 ASIGNAR ASIGNATURA  DOCENTE

void menuAsignarAsignaturaDocente(){
	bool sigueasignado=true;
	while(sigueasignado){
		bool listavacia=false;
		list<string>::iterator it;
		list<string> listaA=icasig_docente->listarAsignaturas();
		if(!listaA.empty()){
			string codigo;
			string email;
			TipoRol rol_m;
			int opciondeRol=false;
			bool terminarTipoRol=true;
			bool selecciono_rol=false;
			int confirmar;

			cout << RED<< "Codigo de asignaturas:" <<RESET<< endl;
			for(it=listaA.begin(); it!=listaA.end();++it){
				cout << *(it) << endl;
			}

			cout<<"\nInserte codigo de Asignatura a Asignar:"<< endl;
			cin >> codigo;

			cout<< "\nDocentes sin asignacion: "<<endl;
			list<string> listaDs=icasig_docente->docentesSinLaAsignatura(codigo);
			if(!listaDs.empty()){//si no esta vacia
				for(it=listaDs.begin(); it!=listaDs.end(); ++it){
						cout<<*(it)<<endl;
					}
					cout<< "Ingrese uno de estos email para continuar:";
					cin>>email;

					while(terminarTipoRol){
						cout << "Ingrese el Rol a cumplir (1 TEORICO, 2 PRACTICO, 3 MONITOREO)" << endl;
						cin >> opciondeRol;
						switch (opciondeRol){
							case(1):rol_m= TEORICO;
									selecciono_rol=true;
									break;
							case(2):rol_m=PRACTICO;
									selecciono_rol=true;
									break;

							case(3):rol_m=MONITOREO;
									selecciono_rol=true;
									break;	
							default:cout<< "Opcion incorrecta."<<endl;
									break;
						}
						if (selecciono_rol){
							terminarTipoRol=false;
							icasig_docente->selectDocente(email,rol_m);
						}else{
							cout <<ORANGE<< "\nNo ha asignado ningun tipo de clase." <<RESET<< endl;
						}

					}

					cout << "\nDesea confirmar la asignacion? (1 para si, cualquier otro numero para no)" << endl;
					cin >> confirmar;

					if(confirmar==1){
						icasig_docente->asignarDocente();
						cout << "\nSe asigno el Docente con exito a la asignatura." << endl;
					} else{
						cout << "\nSe cancelo correctamente." << endl;
					}
			}else{
				cout<<RED<<"\nNo hay ningun Docente"<<RESET<<endl;
				listavacia=true;
				sigueasignado=false;
			}
		}else{
			cout<<RED<<"\nNo hay ningun Asignatura"<<RESET<<endl;
			listavacia=true;
			sigueasignado=false;
		}
		if(!listavacia){
			cout << "Desea seguir asignando Docentes? (0 para seguir asignando, cualquier otro numero para cancelar)" << endl;
			int opcionSeguirAsignando;
			cin >> opcionSeguirAsignando;

			if(opcionSeguirAsignando != 0){
				sigueasignado = false;
			}
		}
	}
}

//4 INSCRIPCION A UNA ASIGNATURA
void menuInscripcionAsignatura(){
    int quiereInscribirse = 0;
    int confirmar;
    string asignaturaElegida;

    while(quiereInscribirse == 0){
        string email;
        cout << "Ingrese el email del estudiante" << endl;
        cin >> email;
        while(!icaltausuario->existeUsuario(email) || !icasistenciaaclaseenvivo->esEstudiante(email)){
            cout << "El email no existe, coloque otro email: ";
            cin >> email;
        }
        cout << "Email ingresado con exito" << endl;
        list<string> asignaturas = icinscripcionasignatura->asignaturasNoInscripto(email);
        if(!asignaturas.empty()){
            list<string>::iterator it;
            for(it = asignaturas.begin(); it != asignaturas.end(); it++){
                cout << *it << endl;
            }
        
            cout << "Elija una de las asignaturas listadas escribiendo su codigo" << endl;
            cin >> asignaturaElegida;
            icinscripcionasignatura->selectAsignatura(asignaturaElegida);
            cout << "Quiere confirmar su eleccion?(0 para confirmar, cualquier otro numero para cancelar)" << endl;
            cin >> confirmar;
            if(confirmar == 0){
                icinscripcionasignatura->inscribir(email);
            }
            cout << "Desea seguir inscribiendose(0 para confirmar, cualquier otro numero para cancelar)" << endl;
            cin >> quiereInscribirse;
        }else{
            cout << "No hay asignaturas a las que pueda inscribirse" << endl;
			cout << "Desea seguir inscribiendose(0 para confirmar, cualquier otro numero para cancelar)" << endl;
            cin >> quiereInscribirse;
        }
    }
}

//5 INICIO CLASE
void menuInicioClase(){
    string codigo;
    string nombre;
    int dia;
    int mes;
    int anio;
    int hora;
    int minuto;
    int segundo;

    string email;
    cout << "Ingrese el email del docente: ";
    cin >> email;

    while(!icaltausuario->existeUsuario(email) || icasistenciaaclaseenvivo->esEstudiante(email)){
        cout << "Ese email no existe, coloque otro email: ";
        cin >> email;
    }

    cout << "Ingrese el codigo de la Asignatura a la que se va a asignar." << endl;
    cin >> codigo;

    cout << "Ingrese el nombre de la Clase a crear." << endl;
	cin.ignore();
	getline(cin, nombre);

    cout << "Ingrese la fecha de inicio:" << endl;
    cout << "Dia: ";
    cin >> dia;
    cout << "Mes: ";
    cin >> mes;
    cout << "Anio: ";
    cin >> anio; 
    DtFecha* fecha = new DtFecha(dia, mes, anio);

    cout << "Ingrese la hora" << endl;
    cout << "Hora: ";
    cin >> hora;
    cout << "Minuto: ";
    cin >> minuto;
    cout << "segundo: ";
    cin >> segundo; 
    DtTimeStamp* fechaHora = new DtTimeStamp(fecha, hora, minuto, segundo);

    int idGenerado = 1;
    DtIniciarMonitoreo* inicioClase = new DtIniciarMonitoreo(codigo, nombre, fechaHora, idGenerado); 

    list<string> asignaturas = icinicioclase->asignaturasAsignadas(email);
	if(!asignaturas.empty()){
		cout << "Asignaturas del docente: " << endl;
		list<string>::iterator it;
		for(it = asignaturas.begin(); it != asignaturas.end(); ++it){
			cout << *it << endl;
		}
		DtIniciarClase* dtic = dynamic_cast<DtIniciarClase*>(inicioClase);
		bool deMonitoreo = icinicioclase->selectAsignatura(dtic, email);
		if(deMonitoreo){
			list<string> estudiantesInscriptos = icinicioclase->inscriptosAsignaturas();
			for(it = estudiantesInscriptos.begin(); it != estudiantesInscriptos.end(); it++){
				cout << *it << endl;
			}
			int quiereHabilitar = 0;
			while(quiereHabilitar == 0){
				string estudianteElegido;
				cout << "Habilite un estudiante ingresando el email" << endl;
				cin >> estudianteElegido;
				icinicioclase->habilitar(estudianteElegido);
				
				cout << "Quiere seguir habilitando estudiantes?(0 para confirmar, cualqueir otro numero para cancelar" << endl;
				cin >> quiereHabilitar;
			}
		}

		cout << "Datos de la clase a ser iniciada" << endl;
		DtIniciarClaseFull* inicioClaseFull = icinicioclase->datosIngresados();
		cout << "Codigo: " <<inicioClaseFull->getCodigo() << endl;
		cout << "Nombre: " << inicioClaseFull->getNombre() << endl;
		cout << *(inicioClaseFull->getFechaHora()) << endl;
		cout << "Id: " << inicioClaseFull->getId() << endl;

		int opcion;
		cout << "Desea confirmar el inicio de esta clase(0 para confirmar, cualquier otro numero para cancelar)" << endl;
		cin >> opcion;
		if(opcion == 0){
			icinicioclase->iniciarClase(email);
			
			cout << "Clase iniciada con exito\nPresione enter para continuar..." << endl;
		}else
			icinicioclase->cancelar();
	}
	else{
		cout<< "No tiene asignaturas asignadas."<<endl;
	}
}

// 6 ASISTENCIA A CLASE EN VIVO
void menuAsistenciaAClaseEnVivo(){
	int id;
	string cod;
	string email;
	bool ingresaMail = true;

	if(!icasistenciaaclaseenvivo->perfilesVacio()){
		if(!icasistenciaaclaseenvivo->asignaturasVacio()){
			if(!icasistenciaaclaseenvivo->clasesVacio()){
				cout << "Ingrese un Email de un Estudiante: ";
				cin >> email;

				while(ingresaMail){
					if(icasistenciaaclaseenvivo->existeUsuario(email) && icasistenciaaclaseenvivo->esEstudiante(email)){
						cout << "Se ha encontrado al perfil y es de un estudiante" << endl;
						ingresaMail = false;
					}else if(icasistenciaaclaseenvivo->existeUsuario(email) && !icasistenciaaclaseenvivo->esEstudiante(email)){
						cout << "El email ingresado no es de un estudiante, ingrese otro email" << endl;
						cin >> email;
					}else if(!icasistenciaaclaseenvivo->existeUsuario(email)){
						cout << "No existe el usuario ingresado, ingrese otro email" << endl;
						cin >> email;
					}
				}

				icasistenciaaclaseenvivo->asignaturasInscripto(email);

				cout << "Ingrese el codigo de la asignatura: ";
				cin >> cod;

				if(icasistenciaaclaseenvivo->estaInscripto(email, cod)){
					if(!icasistenciaaclaseenvivo->asignaturaNoTieneClases(cod)){
						while(!icasistenciaaclaseenvivo->existeAsignatura(cod)){
							cout << "El codigo ingresado no existe, ingrese otro codigo." << endl;
							cin >> cod;
						}

						icasistenciaaclaseenvivo->clasesOnlineDisponibles(cod);

						cout << "Ingrese la ID de la clase: ";
						cin >> id;

						while(!icasistenciaaclaseenvivo->existeClase(id)){
							cout << "El codigo ingresado no existe, ingrese otro codigo." << endl;
							cin >> cod;
						}


						cout << *(icasistenciaaclaseenvivo->selectClase(id)) << endl;

						cout << "Desea confirmar la asistencia? (1 para si, cualquier otro numero para no)" << endl;
						int opcionFinal;
						cin >> opcionFinal;
						
						if(opcionFinal==1){
							icasistenciaaclaseenvivo->asistirClaseEnVivo();
						}
					}else{
						cout << "La Asignatura no tiene Clases registradas." << endl;
					}
				}else{
					cout << "El estudiante no esta inscripto a esta materia." << endl;
				}
			}else{
				cout << "No hay ninguna Clase registrada." << endl;
			}
		}else{
			cout << "No hay ninguna Asignatura registrada." << endl;
		}
	}else{
		cout << "No hay ningun Perfil registrado." << endl;
	}

}

// 7 ENVIO DE MENSAJE

void menuEnvioDeMensaje(){
	string email;
	list<int> participaciones;
	list<DtParticipacion*> mensajes;
	list<int>::iterator it;
	list<DtParticipacion*>::iterator it2;
	int id;
	int idp;
	bool enRespuesta = false;
	int op = 1;
	string txt;

	cout<<"Ingrese su email para verificar usuario:"<<endl;
	cin >>email;
	
	while(!icaltausuario->existeUsuario(email)){
		cout << "Usuario no encontrado, coloque otro email: ";
		cin >> email;
	}

	icenvio_mensaje->verificarPerfil(email);

	participaciones = icenvio_mensaje->clasesOnLineAsistiendo();
	if(!participaciones.empty()){
		cout<<"Sus clases disponibles son:"<<endl;
		cout<<"==========================:"<<endl;
		for(it = participaciones.begin();it != participaciones.end(); ++it){
			cout << *it <<endl;
		}
		cout<<"Seleccione un id del listado:"<<endl;
		cin>>id;
		mensajes = icenvio_mensaje->selectClase(id);
		if(!mensajes.empty()){
			cout<<"Mensajes de la Clase:"<<endl;
			cout<<"==========================:"<<endl;
			for(it2 = mensajes.begin();it2 != mensajes.end(); ++it2){
				cout<< *(*it2) <<endl;// hacer friend cout << en DtParticipacion
			}
			cout<<"Desea responder a alguno de estos mensajes? [ 0 = SI || 1 = NO]"<<endl;
			cin>>op;
			if(op==0){
				enRespuesta = true;
				cout<< "Ingrese id del mensaje a responder:"<<endl;
				cin>>idp;
				icenvio_mensaje->responder(idp);

			}			
		}
		else{
			cout<<"Esta clase no tiene mensajes."<<endl;
		}
		cout<<"Ingrese su mensaje:"<<endl;
		cin.ignore();
		getline(cin,txt);
		icenvio_mensaje->ingresarTexto(txt);

		cout<<"Desea confirmar el mensaje? [ 0 = SI || 1 = NO]"<<endl;
		cin>>op;
		
		if(op==0){
			icenvio_mensaje->enviarMensaje();
			cout<<"Se ha enviado el mensaje correctamente."<<endl<<endl;
		}
		else{
			icenvio_mensaje->cancelar();
			cout<<"Mensaje cancelado."<<endl;
		}

	}
	else{
		cout <<"No tiene clases a las que pueda enviar un mensaje."<<endl;
	}



}

// 8 ELIMINAR ASIGNATURA

void menuEliminarAsignatura(){

	string codigo;
	
	list<string> listasA = iceliminar_asignatura->listarAsignaturas();
	list<string>::iterator it;
	
	if(!listasA.empty()){
		for(it=listasA.begin(); it != listasA.end(); it++){
			cout<<(*it)<<endl;
		}
		cout << "Ingrese un codigo de asignatura: ";
		cin >> codigo;

		while(!iceliminar_asignatura->existeAsignatura(codigo)){
			cout << "No existe una asignatura con ese codigo, vuelva a ingresar un codigo." << endl;
			cin >> codigo;
		}

		iceliminar_asignatura->selectAsignatura(codigo);

		cout << "Desea eliminar la Asignatura? (1 para si, cualquier otro numero para no)"<<endl;
		int opcionFinal;
		cin >> opcionFinal;

		if(opcionFinal == 1){
			iceliminar_asignatura->eliminarAsignatura();
		}
	}
	else{
		cout<<RED<<"\nNo hay ningun Asignatura"<<RESET<<endl;
	}

}

// 9 LISTAR CLASE

void menuListadoClases(){
	string codigoAsign;
	string emailDoc;
	cout << "Ingrese el Email del docente: " << endl; 
	cin >> emailDoc;
	
	while(!icaltausuario->existeUsuario(emailDoc) || icasistenciaaclaseenvivo->esEstudiante(emailDoc)){
		cout << "Usuario no reconocido o es un alumno" << endl;
		cin >> emailDoc;
	}

	cout << "Asignaturas de " << emailDoc << endl;
	cout << "========================" << endl;
	list<string> asigAsignadas = iclistado_clases->asignaturasAsignadas(emailDoc);
	list<string>::iterator it1;
	for(it1 = asigAsignadas.begin(); it1 != asigAsignadas.end(); it1++){
		cout << *it1 << endl;
	}

	cout << "Ingrese un codigo de una Asignatura: " << endl;
	cin >> codigoAsign;
	cout << endl;

	while(!icalta_asignatura->existeAsignatura(codigoAsign) || icasistenciaaclaseenvivo->asignaturaNoTieneClases(codigoAsign)){
		cout << "No existe una asignatura con ese codigo o bien no tiene clases iniciadas" << endl;
		cin >> codigoAsign;
	}


	cout << "Clases de la asignatura: " << endl;
	map<int, DtInfoClase*>::iterator it2;
	map<int, DtInfoClase*> clasesAsignatura = iclistado_clases->selectAsignatura(codigoAsign);
	for(it2 = clasesAsignatura.begin(); it2 != clasesAsignatura.end(); it2++){
		DtInfoClase* dtic = (*it2).second;

		cout << *dtic << endl;
		if(DtInfoTeorico* dtit = dynamic_cast<DtInfoTeorico*>(dtic)){
			cout << *dtit << endl;
		}else if (DtInfoMonitoreo* dtim = dynamic_cast<DtInfoMonitoreo*>(dtic)){
			cout << *dtim << endl;
		}
	}
}


void cargarDatosDePrueba(){
	
	//CREACION DE PERFILES
	
	//Estudiante 1
	DtPerfil* datosperfil1 = new DtPerfil("juan", "img.jpg", "juan@gmail.com", "123");
	icaltausuario->ingresarDatosPerfil(datosperfil1);
	icaltausuario->ingresarEstudiante("5229001-1");
	icaltausuario->altaUsuario();
	//Estudiante 2
	DtPerfil* datosperfil2 = new DtPerfil("verita", "img.jpg", "verita@gmail.com", "321");
	icaltausuario->ingresarDatosPerfil(datosperfil2);
	icaltausuario->ingresarEstudiante("5229002-1");
	icaltausuario->altaUsuario();

	//Docente 1
	DtPerfil* datosperfil3 = new DtPerfil("jose", "img.jpg", "jose@gmail.com", "456");
	icaltausuario->ingresarDatosPerfil(datosperfil3);
	icaltausuario->ingresarDocente("LATUTU");
	icaltausuario->altaUsuario();
	//Docente 2
	DtPerfil* datosperfil4 = new DtPerfil("chancla", "img.jpg", "master@chancla.com", "132");
	icaltausuario->ingresarDatosPerfil(datosperfil4);
	icaltausuario->ingresarDocente("CHANCLETA");
	icaltausuario->altaUsuario();

	//CREACION DE ASIGNATURAS

	//Asignatura1
	DtInstanciaClase* instanciaClase1 = new DtInstanciaClase(true, false, false);
	DtAsignatura* datosAsignatura1 = new DtAsignatura("Matematica", "mat", instanciaClase1);
	icalta_asignatura->ingresar(datosAsignatura1);
	icalta_asignatura->altaAsignatura();
	
	//Asignatura2
	DtInstanciaClase* instanciaClase2 = new DtInstanciaClase(true, false, false);
	DtAsignatura* datosAsignatura2 = new DtAsignatura("Programacion", "pav", instanciaClase2);
	icalta_asignatura->ingresar(datosAsignatura2);
	icalta_asignatura->altaAsignatura();

	//Asignatura3
	DtInstanciaClase* instanciaClase3 = new DtInstanciaClase(true, false, false);
	DtAsignatura* datosAsignatura3 = new DtAsignatura("Filosofia", "filo", instanciaClase3);
	icalta_asignatura->ingresar(datosAsignatura3);
	icalta_asignatura->altaAsignatura();

	//ASIGNACION DE ESTUDIANTE Y DOCENTE A ASIGNATURAS
	icasig_docente->docentesSinLaAsignatura("pav");
    icasig_docente->selectDocente("jose@gmail.com", TEORICO);
    icasig_docente->asignarDocente();
	
	icasig_docente->docentesSinLaAsignatura("filo");
    icasig_docente->selectDocente("jose@gmail.com", MONITOREO);
    icasig_docente->asignarDocente();

	icasig_docente->docentesSinLaAsignatura("filo");
    icasig_docente->selectDocente("master@chancla.com", MONITOREO);
    icasig_docente->asignarDocente();
	
    icinscripcionasignatura->selectAsignatura("pav");
    icinscripcionasignatura->inscribir("juan@gmail.com");

	icinscripcionasignatura->selectAsignatura("filo");
    icinscripcionasignatura->inscribir("juan@gmail.com");

	//INICIO DE CLASES

	DtFecha* fecha = new DtFecha(12, 8, 2021);
	DtTimeStamp* fechaHora = new DtTimeStamp(fecha, 13, 05, 00);
	
	int idGenerado = 1;
	DtIniciarMonitoreo* inicioClase = new DtIniciarMonitoreo("pav", "Pavsito", fechaHora, idGenerado);
	icinicioclase->asignaturasAsignadas("jose@gmail.com");
	DtIniciarClase* dtic = dynamic_cast<DtIniciarClase*>(inicioClase);
 	icinicioclase->selectAsignatura(dtic, "jose@gmail.com");
	icinicioclase->datosIngresados();
	icinicioclase->iniciarClase("jose@gmail.com");
	cout << "Clase iniciada con exito\nPresione enter para continuar..." << endl;
	

}

int main(){

	icaltausuario = fab->getCAltaUsuario();
	icalta_asignatura = fab->getCAltaAsignatura();
	icasistenciaaclaseenvivo = fab->getCAsistenciaAClaseEnVivo();
	icasig_docente = fab->getCAsignarAsignaturaDocente();
	iceliminar_asignatura = fab->getCEliminarAsignatura();
	icinscripcionasignatura = fab->getCInscripcionAsignatura();
	icinicioclase = fab->getCInicioClase();
	icenvio_mensaje = fab->getCEnvioDeMensaje();
	iclistado_clases =fab->getCListadoClases();

	bool datosCargados = false;

    int opcion;
    menu();
    cin >> opcion;

    while(opcion != 11){
		
        switch(opcion){
            case 1: menuAltaUsuario();
                    break;
            case 2:	menuAltaAsignatura();
                    break;
            case 3: menuAsignarAsignaturaDocente();
                    break;
            case 4: if(!icinscripcionasignatura->perfilesVacio() && !icinscripcionasignatura->asignaturasVacio()){
                        menuInscripcionAsignatura();
                    }else{
                        cout << "Faltan perfiles o asignaturas en el sistema para ejecutar esta funcion" << endl;
                    }
                    break;
            case 5: if(!icinicioclase->perfilesVacio() && !icinscripcionasignatura->asignaturasVacio()){
                        menuInicioClase();
                    }else{
                        cout << "Faltan perfiles o asignaturas en el sistema para ejecutar esta funcion" << endl;
                    }
                    break;
            case 6: menuAsistenciaAClaseEnVivo();
                    break;
            case 7: menuEnvioDeMensaje();
                    break;
            case 8:	menuEliminarAsignatura();
                    break;
            case 9: menuListadoClases();
                break;
            case 10:if(!datosCargados){
                  		cargarDatosDePrueba();
                  		datosCargados = true;
                  		cout << "Datos de prueba cargados con exito." << endl;
                	}else
                  		cout << "Los datos de prueba ya fueron cargados." << endl;
                break;
            case 11:
                break;
            default: cout << "Opcion invalida." << endl;
                 break;
        }
		cin.ignore();
		menu();
		cin >> opcion;//limpiar bufer
    }
    return 0;
}