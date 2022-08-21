CPP = g++
CPPFLAGS = -Wall -Werror -std=c++11 $(DEBUG)
ifeq ($(D),1)
    DEBUG = -g
endif
EXECUTABLES = base_converter print_signed_rep decode_float

all: $(EXECUTABLES)

%: %.cpp
	$(CPP) $(CPPFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLES)
