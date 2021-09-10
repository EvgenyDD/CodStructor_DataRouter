#include "mns.cpp"
#include "mns.h"

int main(void)
{
	printf("--- DR Test ---\n");

	dr_init();

	dr_type_t *tx_type_str = dr_new_type("string");
	dr_type_t *tx_type_str2 = dr_new_type("string2");
	dr_del_type("string2");
	// dr_del_type("strings");
	dr_type_t *tx_type_str3 = dr_new_type("string3");
	dr_type_t *tx_type_str8 = dr_new_type("string4");

	dr_new_tx("string4");

	// int rx_ch_str = dr_new_rx(tx_type_str, 0, );
	// int rx_ch_str2 = dr_new_rx("string", 0, );

	// int tx_chnl_str1 = dr_new_chnl(tx_type_str, "0");

	return 0;
}