
/* region.h */

typedef struct region_s
{
	struct region_s *next;
	MARK	from, to;	/* endpoints of region */
	CHAR	*comment;	/* comment */
	ELVFACE	font;		/* face code */
} region_t;

void regionadd P_((MARK from, MARK to, _ELVFACE_ font, CHAR *comment));
void regiondel P_((MARK from, MARK to, _ELVFACE_ font));
region_t *regionfind P_((MARK mark));
void regionundo P_((BUFFER buf, struct umark_s *keep));
