#include <iostream>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <functional>

#include "lua.hpp"

struct Data
{
    int x, y, z;
    char c;
};

template <typename T>
void bind_class(lua_State* L)
{
	T* userdata = reinterpret_cast<T*>(lua_newuserdata(L, sizeof(T)));
	new(userdata) T();
}

int main(int argc, char** argv)
{
	std::vector<int> d;
	lua_State* L = luaL_newstate();
	luaL_openlibs(L);
	bind_class<Data>(L);

	return 0;
}