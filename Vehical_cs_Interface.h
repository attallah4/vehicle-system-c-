#ifndef VEHICAL_CS_INTERFACE_H_INCLUDED
#define VEHICAL_CS_INTERFACE_H_INCLUDED

void vehical_menu_init(void);

void turn_on(void);

void set_traffic_light(void);

void set_engine_temp(void);

void set_room_temp(void);

void print_states(void);

typedef enum{
OFF,
ON
}STATUS_T;

#endif // VEHICAL_CS_INTERFACE_H_INCLUDED
