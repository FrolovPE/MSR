CXX = g++
CXXFLAGS = -O3 -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format
TSAN =  $(parallel) -fsanitize=thread
GPRO3 = -pg $(cxx)
GPR = -pg $(wo3)
WO3 = -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format
TARGET = a.out
OBJS = main.o msr.o mytime.o extpll.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp msr.h mytime.h
	$(CXX) $(CXXFLAGS) -c main.cpp

msr.o: msr.cpp msr.h mytime.h
	$(CXX) $(CXXFLAGS) -c msr.cpp

mytime.o: mytime.cpp mytime.h
	$(CXX) $(CXXFLAGS) -c mytime.cpp

extpll.o: extpll.cpp extpll.h
	$(CXX) $(CXXFLAGS) -c extpll.cpp

clean:
	rm -f $(OBJS) $(TARGET)

mainzip:
	zip Frolov_PS.zip $(OBJS) makefile 

zip:
	zip pll.zip $(OBJS) makefile