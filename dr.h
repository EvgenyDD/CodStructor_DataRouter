#ifndef DR_H_
#define DR_H_

/// Data Router Library

#include <list>
#include <stdint.h>
#include <string>

typedef struct
{
	void *data;
	int timestamp; // optional
} dr_msg_t;

typedef struct
{
	std::list<dr_msg_t> queue;
} dr_q_t;

typedef struct
{
	int id;
	std::string name;
	dr_q_t q;
} dr_listener_t;

typedef struct
{
	int id;
	std::string name;
	std::list<dr_listener_t> listeners;
} dr_chnl_t;

typedef struct
{
	int id;
	std::string name;
	std::list<dr_chnl_t> channels;
	std::list<int> chnl_id;
} dr_type_t;

void dr_init(void);

dr_type_t *dr_new_type(std::string name, int size);
int dr_del_type(std::string name);

int dr_new_tx(std::string name_type, std::string name_tx);

#endif // DR_H_