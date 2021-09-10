#include "mns.h"
#include <algorithm>

/// Data Router Library

static std::list<dr_type_t> types;
static std::list<int> type_id;

#define DR_PRINT_ERROR(...) \
	printf("[E] DR: ");     \
	printf(__VA_ARGS__);

#define DR_PRINT_INFO(...) \
	printf("[I] DR: ");    \
	printf(__VA_ARGS__);

void dr_init(void)
{
}

static dr_type_t *_find_type(std::string name)
{
	for(auto &a : types)
	{
		if(a.name == name)
		{
			return &a;
		}
	}
	return nullptr;
}

dr_type_t *dr_new_type(std::string name)
{
	for(auto a : types)
	{
		if(a.name == name)
		{
			DR_PRINT_ERROR("Type with name: \"%s\" already exists, id: %d\n", name.c_str(), a.id);
			return nullptr;
		}
	}

	int num = 0;
	type_id.sort();
	for(auto i : type_id)
	{
		if(num != i) break;
		num++;
	}
	type_id.push_back(num);

	types.emplace_back(dr_type_t{.id = num, .name = name});
	DR_PRINT_INFO("Type +, id: %d, name: \"%s\"\n", types.back().id, types.back().name.c_str());
	return &types.back();
}

int dr_del_type(std::string name)
{
	auto i{types.begin()};
	while(i != types.end())
	{
		if((*i).name == name)
		{
			DR_PRINT_INFO("Type -, id: %d, name: \"%s\"\n", (*i).id, (*i).name.c_str());
			type_id.erase(std::remove_if(type_id.begin(), type_id.end(), [&](int x)
			                             { return x == (*i).id; }),
			              type_id.end());
			types.erase(i);
			return 0;
		}
		i++;
	}
	DR_PRINT_ERROR("Type - fail, not exists, name: \"%s\"\n", name.c_str());
	return 1;
}

int dr_new_tx(std::string name_type, std::string name_tx = "")
{
	if(_find_type(name_type) == nullptr)
	{
		DR_PRINT_ERROR("Tx + fail, type: \"%s\" not exists\n", name_type.c_str());
	}
	printf("ntx\n");
	return 0;
}
