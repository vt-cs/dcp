gxx = g++

source_dir = .
header_dir = .
binary_dir = .

binary_name = solution

libs =
cflags = -Wall

inc = -I $(header_dir)/

src = $(wildcard $(source_dir)/*.cpp)

all : $(src)
	$(gxx) -o $(binary_dir)/$(binary_name) $^ $(cflags) $(libs) $(inc)

clean :
	rm -rf $(binary_dir)/$(binary_name)
