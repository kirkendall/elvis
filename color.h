/* color.h */

/* ELVFACE is the data type for the subscript of colorinfo.  With multiple
 * windows each generating their own combined typefaces, we need a lot of
 * entries here.  We also need one bit to flag "selected" text.
 */
typedef short ELVFACE;
typedef int _ELVFACE_;/* promoted type, for K&R compatibility */
#define SELECTED_BIT 0x800
#define FACE_BITS (SELECTED_BIT - 1)
