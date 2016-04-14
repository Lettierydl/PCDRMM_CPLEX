SYSTEM	= x86-64_darwin9_gcc4.0
LIBFORMAT = static_pic

OPTIONS = -O0 -w #-g
COMP = g++ -c

#------------------------------------------------------------
#
# When you adapt this makefile to compile your CPLEX programs
# please copy this makefile and set CPLEXDIR and CONCERTDIR to
# the directories where CPLEX and CONCERT are installed.
#
#------------------------------------------------------------
			
CPLEXDIR = /Users/Lettiery/Applications/IBM/ILOG/CPLEX_Studio124/cplex
CONCERTDIR  = /Users/Lettiery/Applications/IBM/ILOG/CPLEX_Studio124/concert
# ---------------------------------------------------------------------
# Compiler selection
# ---------------------------------------------------------------------


CPPC = g++ $(OPTIONS)

# ---------------------------------------------------------------------
# Compiler options
# ---------------------------------------------------------------------
#g++ -O0  -m64 -O -fPIC -fexceptions -DNDEBUG -DIL_STD -stdlib=libstdc++ 
#-I/Users/Leo/Applications/IBM/ILOG/CPLEX_Studio124/cplex/include
#-I/Users/Leo/Applications/IBM/ILOG/CPLEX_Studio124/concert/include
#-o PCDRMM_CPLEX *.cpp
#-L/Users/Leo/Applications/IBM/ILOG/CPLEX_Studio124/cplex/lib/x86-64_darwin9_gcc4.0/static_pic
#-lilocplex -lcplex
#-L/Users/Leo/Applications/IBM/ILOG/CPLEX_Studio124/concert/lib/x86-64_darwin9_gcc4.0/static_pic
#-lconcert
#-m64 -lm -lpthread -framework CoreFoundation -framework IOKit

CCOPT = -m64 -O -fPIC -fexceptions -DNDEBUG -DIL_STD -stdlib=libstdc++
COPT  = -m64 -fPIC

# ---------------------------------------------------------------------
# Link options and libraries
# ---------------------------------------------------------------------


CPLEXBINDIR   = $(CPLEXDIR)/bin/$(BINDIST)
CPLEXLIBDIR   = $(CPLEXDIR)/lib/$(SYSTEM)/$(LIBFORMAT)
CONCERTLIBDIR = $(CONCERTDIR)/lib/$(SYSTEM)/$(LIBFORMAT)


CCLNDIRS  = -L$(CPLEXLIBDIR) -L$(CONCERTLIBDIR)
CLNDIRS   = -L$(CPLEXLIBDIR)
CLNFLAGS  = -lcplex -lm -lpthread -framework CoreFoundation -framework IOKit


CCLNFLAGS = -L$(CPLEXLIBDIR) -lilocplex -lcplex -L$(CONCERTLIBDIR) -lconcert -m64 -lm -lpthread -framework CoreFoundation -framework IOKit



CONCERTINCDIR = $(CONCERTDIR)/include
CPLEXINCDIR   = $(CPLEXDIR)/include
#SRCDIR = ~/CPLEX\ Teste


CCFLAGS = $(CCOPT) -I$(CPLEXINCDIR) -I$(CONCERTINCDIR)

all:clean PCDRMM_CPLEX

PCDRMM_CPLEX:PCDRMM_CPLEX.cpp 
		 $(CPPC) $(CCFLAGS) -o PCDRMM_CPLEX *.cpp $(CCLNFLAGS)
	
	
clean:
		rm -rf PCDRMM_CPLEX *.o ag *~ *.oo core* -f

	