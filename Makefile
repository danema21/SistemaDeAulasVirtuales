#OBJS seria una especie de contenedor donde se van a escribir por unica vez todos los archivos objeto
OBJS = main.o Perfil.o Estudiante.o Docente.o DtTimeStamp.o DtFecha.o DtLog.o \
       Rol.o Participacion.o Practico.o Teorico.o Monitoreo.o Clase.o Asignatura.o \
	   AsisteEnVivo.o AsisteDiferido.o CAltaUsuario.o CInicioClase.o \
	   DtPerfil.o ManejadorPerfil.o Fabrica.o DtIniciarClase.o DtIniciarClaseFull.o \
	   DtAsignatura.o DtInstanciaClase.o ManejadorAsignatura.o CAltaAsignatura.o DtAsistir.o\
	   CAsistenciaAClaseEnVivo.o ManejadorClase.o CAsignarAsignaturaDocente.o\
	   DtIniciarMonitoreo.o CEliminarAsignatura.o CInscripcionAsignatura.o DtInfoClase.o DtInfoTeorico.o\
	   DtInfoMonitoreo.o CListadoClases.o CEnvioDeMensaje.o DtParticipacion.o


main: $(OBJS)
	g++ $(OBJS) -g -o sistema

#Metodo para relacionar cada objeto con su .cpp correspondiente(Nos ahorramos escribir un metodo para cada objeto)	
%.o: %.cpp
	g++ -g -c -MD $<
# Se usa $< para el .cpp (o segundo atb) y $@ para .o
# -MD hace referencia a las dependencias de los .h - Crea archivos .d
#que contienen de que .h depende cada archivo.  
-include *.d

clean:
	rm -rf *.o *.d sistema
	clear
