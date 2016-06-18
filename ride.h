#ifndef DAT_RIDE_H_INCLUDED
#define DAT_RIDE_H_INCLUDED



#define TILE_SLOPE (1/sqrt(6))

#define FLAT 0

#define GENTLE (atan(TILE_SLOPE))
#define STEEP (atan(4*TILE_SLOPE))
#define VERTICAL M_PI_2
#define FG_TRANSITION ((FLAT+GENTLE)/2)
#define GS_TRANSITION ((GENTLE+STEEP)/2)
#define SV_TRANSITION ((STEEP+VERTICAL)/2)

#define GENTLE_DIAGONAL (atan(TILE_SLOPE*M_SQRT1_2))
#define STEEP_DIAGONAL (atan(4*TILE_SLOPE*M_SQRT1_2))
#define FG_TRANSITION_DIAGONAL ((FLAT+GENTLE_DIAGONAL)/2)

#define BANK M_PI_4
#define BANK_TRANSITION (M_PI_4/2)


#define CORKSCREW_RIGHT_YAW(angle) (atan2(0.5*(1-cos(angle)),1-0.5*(1-cos(angle))))
#define CORKSCREW_RIGHT_PITCH(angle) (-asin(-sin(angle)/sqrt(2.0)))
#define CORKSCREW_RIGHT_ROLL(angle) (-atan2(sin(angle)/sqrt(2.0),cos(angle)))

#define CORKSCREW_LEFT_YAW(angle) (-CORKSCREW_RIGHT_YAW(angle))
#define CORKSCREW_LEFT_PITCH(angle) (-CORKSCREW_RIGHT_PITCH(-angle))
#define CORKSCREW_LEFT_ROLL(angle) (-CORKSCREW_RIGHT_ROLL(angle))


#define NUM_CARS 4

enum //Ride flags
{
RIDE_WET=0x00000100u,
RIDE_COVERED=0x00000400u,
RIDE_SLOW_IN_WATER=0x00000200u,
RIDE_SEPERATE=0x00001000u,
RIDE_ENABLE_OR_ELSE=0x00002000u //Not setting this prevents track designs from showing in the window
}ride_flags_t;
enum //Vehicle flags
{
CAR_ENABLE_REMAP2=0x01000000u,
CAR_ENABLE_REMAP3=0x00020000u,
CAR_IS_SWINGING=0x02000000u,
CAR_IS_SPINNING=0x04000000u,
CAR_IS_POWERED=0x08000000u,
CAR_NO_UPSTOPS=0x00000400u,
CAR_ENABLE_ROLLING_SOUND=0x10000000u,
CAR_FAKE_SPINNING=0x00000001u
}car_flags_t;
enum //Sprite flags
{
SPRITE_FLAT_SLOPE=0x0001,
SPRITE_GENTLE_SLOPE=0x0002,
SPRITE_STEEP_SLOPE=0x0004,
SPRITE_VERTICAL_SLOPE=0x0008,
SPRITE_DIAGONAL_SLOPE=0x0010,
SPRITE_BANKING=0x0020,
SPRITE_INLINE_TWIST=0x0040,
SPRITE_SLOPE_BANK_TRANSITION=0x0080,
SPRITE_DIAGONAL_BANK_TRANSITION=0x0100,
SPRITE_SLOPED_BANK_TRANSITION=0x0200,
SPRITE_SLOPED_BANKED_TURN=0x0400,
SPRITE_BANKED_SLOPE_TRANSITION=0x0800,
SPRITE_CORKSCREW=0x1000,
SPRITE_RESTRAINT_ANIMATION=0x2000,
SPRITE_SPIRAL_LIFT=0x4000
}sprite_flags_t;
enum //Ride primary sounds
{
RUNNING_SOUND_WOODEN_OLD=1,
RUNNING_SOUND_WOODEN_MODERN=54,
RUNNING_SOUND_STEEL=2,
RUNNING_SOUND_STEEL_SMOOTH=57,
RUNNING_SOUND_WATERSLIDE=32,
RUNNING_SOUND_TRAIN=31,
RUNNING_SOUND_ENGINE=21,
RUNNING_SOUND_NONE=255
}running_sound_t;
enum //Ride secondary sounds
{
SECONDARY_SOUND_SCREAMS_1=0,
SECONDARY_SOUND_SCREAMS_2=1,
SECONDARY_SOUND_SCREAMS_3=2,
SECONDARY_SOUND_WHISTLE=3,
SECONDARY_SOUND_BELL=4,
SECONDARY_SOUND_NONE=255,
}secondary_sound_t;
enum //Car position indices
{
CAR_INDEX_DEFAULT=0,
CAR_INDEX_FRONT=1,
CAR_INDEX_SECOND=2,
CAR_INDEX_THIRD=4,
CAR_INDEX_REAR=3
}car_index_t;
enum //Ride categories
{
CATEGORY_TRANSPORT_RIDE=0,
CATEGORY_GENTLE_RIDE=1,
CATEGORY_ROLLERCOASTER=2,
CATEGORY_THRILL_RIDE=3,
CATEGORY_WATER_RIDE=4
}category_t;



#define TRACK_STATION 0x0000000000000004l
#define TRACK_STRAIGHT 0x0000000000000002l
#define TRACK_CHAIN_LIFT 0x0000000000000008l
#define TRACK_STEEP_CHAIN_LIFT 0x0000000000000010l
#define TRACK_TIRE_DRIVE_LIFT 0x0000000000000020l //Junior only
#define TRACK_BANKING 0x0000000000000040l
#define TRACK_VERTICAL_LOOP 0x0000000000000080l
#define TRACK_GENTLE_SLOPE 0x0000000000000100l
#define TRACK_STEEP_SLOPE 0x0000000000000200l
#define TRACK_FLAT_TO_STEEP_SLOPE_SMALL 0x0000000000000400l
#define TRACK_SLOPED_TURNS 0x0000000000000800l //(Enables available turns)
#define TRACK_STEEP_SLOPED_TURNS 0x0000000000001000l
#define TRACK_S_BEND 0x0000000000002000l
#define TRACK_TINY_TURNS 0x0000000000004000l
#define TRACK_SMALL_TURN 0x0000000000008000l //(Flat enabled)
#define TRACK_LARGE_TURN 0x0000000000010000l
#define TRACK_INLINE_TWIST 0x0000000000020000l
#define TRACK_HALF_LOOP 0x0000000000040000l
#define TRACK_HALF_CORKSCREW 0x0000000000080000l
#define TRACK_VERTICAL_TOWER 0x0000000000100000l //Launched Freefall + Roto-Drop?)
#define TRACK_HELIX 0x0000000000200000l //(For upright track only)
#define TRACK_QUARTER_HELIX 0x0000000000400000l //(For inverted track only)
#define TRACK_UNBANKED_QUARTER_HELIX 0x0000000000800000l //Suspended Swinging only
#define TRACK_BRAKES 0x0000000001000000l
#define TRACK_ON_RIDE_PHOTO_SECTION 0x0000000004000000l
#define TRACK_WATER_SPLASH 0x0000000008000000l //Wooden only
#define TRACK_VERTICAL_SLOPE 0x0000000010000000l
#define TRACK_BARREL_ROLL 0x0000000020000000l
#define TRACK_LAUNCHED_LIFT 0x0000000040000000l
#define TRACK_LARGE_HALF_LOOP 0x0000000080000000l
#define TRACK_BANKED_FLAT_TO_UNBANKED_GENTLE_SLOPE_TURN 0x0000000100000000l
#define TRACK_HEARTLINE_ROLL 0x0000000400000000l //Heartline only
#define TRACK_REVERSER_TURNTABLE 0x0000000200000000l //Log Flume only
#define TRACK_REVERSER 0x0000000800000000l //Reverser only
#define TRACK_FLAT_TO_VERTICAL_SLOPE 0x0000001000000000l //Enables vertical track
#define TRACK_VERTICAL_TO_FLAT 0x0000002000000000l //Enables top section
#define TRACK_BLOCK_BRAKES 0x0000004000000000l
#define TRACK_GENTLE_SLOPE_BANKING 0x0000008000000000l //(Enables available turns)
#define TRACK_FLAT_TO_STEEP_SLOPE 0x0000010000000000l
#define TRACK_VERTICAL_SLOPED_TURNS 0x0000020000000000l
#define TRACK_CABLE_LIFT 0x0000080000000000 //Giga only
#define TRACK_SPIRAL_LIFT 0x0000100000000000l //Spiral Coaster only
#define TRACK_QUARTER_LOOP 0x0000200000000000l
#define TRACK_SPINNING_TUNNEL 0x0000400000000000l //(Ghost Train and Car Rides)
#define TRACK_SPINNING_TOGGLE 0x0000800000000000l //Spinning Wild Mouse only)
#define TRACK_INLINE_TWIST_UNINVERT 0x0001000000000000l
#define TRACK_INLINE_TWIST_INVERT 0x0002000000000000l
#define TRACK_QUARTER_LOOP_INVERT 0x0004000000000000l
#define TRACK_QUARTER_LOOP_UNINVERT 0x0008000000000000l
#define TRACK_RAPIDS 0x0010000000000000l //Rapids / Log Bumps, River Rapids / Monster Trucks only
#define TRACK_HALF_LOOP_UNINVERT 0x0020000000000000l
#define TRACK_HALF_LOOP_INVERT 0x0040000000000000l


typedef uint64_t track_section_t;


typedef struct //Vehicle struct
{
uint32_t flags;
uint32_t spacing;
uint16_t unknown[9];
uint16_t sprites;
uint16_t friction;
uint8_t running_sound;
uint8_t secondary_sound;
uint8_t extra_swing_frames;
uint8_t highest_rotation_index;
uint8_t rider_pairs;
uint8_t riders;
uint8_t rider_sprites;
uint8_t spin_inertia;
uint8_t spin_friction;
uint8_t powered_acceleration;
uint8_t powered_velocity;
uint8_t z_value;
}car_t;

typedef struct //Ride header
{
uint64_t track_sections;
uint32_t flags;
uint8_t car_icon_index;
uint8_t zero_cars;
uint8_t preview_index;
uint8_t track_style;
uint8_t excitement;
uint8_t intensity;
uint8_t nausea;
uint8_t max_height;
uint8_t categories[2];
uint8_t car_types[5];
uint8_t minimum_cars;
uint8_t maximum_cars;
car_t cars[NUM_CARS];
}ride_header_t;

//Ride optional data
typedef struct
{
uint8_t colors[3];
}color_scheme_t;

typedef struct
{
uint8_t* positions;
uint16_t num;
}peep_position_data_t;

typedef struct
{
color_scheme_t* default_colors;
uint8_t num_default_colors;
peep_position_data_t peep_positions[4];
}ride_structures_t;

/*
ride_header_t* ride_header_new();
ride_structures_t* ride_structures_new();
void ride_structures_set_num_peep_positions(ride_structures_t* structures,int car,int num);
void ride_structures_set_num_default_colors(ride_structures_t* structures,int num);
*/

struct object_s* object_new_ride();
void object_ride_load(struct object_s* object,uint8_t* bytes,uint32_t* pos_ptr);
//void object_ride_write(struct object_s* object,buffer_t* buffer);
void object_free_ride(struct object_s* object);



#endif // DAT_RIDE_H_INCLUDED