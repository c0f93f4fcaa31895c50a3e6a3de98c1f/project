#Author : Simons<liyuling@xunlei.com>
#Date	: 2017-09-18 11:25

TARGET:=sklist
COBJS:=$(patsubst %.c,%.o,$(wildcard *.c))
COBJS+=$(patsubst %.cpp,%.o,$(wildcard *.cpp))

.PHONY:all clean distclean install
all: $(TARGET)
$(TARGET):$(COBJS)
	$(CPP) -o $@ $(COBJS) $(LDFLAGS)

%.d:%.c
	-@$(CC) -MM $(CFLAGS) $< > $@
%.d:%.cpp
	-@$(CPP) -MM $(CPPFLAGS) $< > $@

-include $(COBJS:.o=.d)

distclean:
	-@$(RM) $(TARGET) $(COBJS) *.d
clean:
	-@$(RM) $(TARGET) $(COBJS) *.d

install:

