
#include "minirt_int.h"

static const char	*cam_lst[] = {"PERSPECTIVE", "UNKNOWN"};
static const char	*lgt_lst[] = {"AMBIENT", "POINT", "UNKNOWN"};
static const char	*obj_lst[] = {"SPHERE", "PLANE", "CYLINDER", "UNKNOWN"};

void	mrt_int_debug_print_cam(t_base_cam *ptr)
{
	if (ptr == NULL)
		return ;

	printf("type   -> %s\n", cam_lst[ptr->type]);
	printf("coord  -> x:%f y:%f z:%f\n", ptr->pos.x, ptr->pos.y, ptr->pos.z);
	printf("view   -> x:%f y:%f z:%f\n", ptr->view.x, ptr->view.y, ptr->view.z);
	switch (ptr->type)
	{
		case (CAM_PERSPECTIVE):
			t_cam_persp	*persp;

			persp = (t_cam_persp *)ptr;
			printf("fov    -> %f\n", persp->fov);
			break ;
		default :
			;
	}
	printf("\n");
}

void	mrt_int_debug_print_lgt(t_base_lgt *ptr)
{
	if (ptr == NULL)
		return ;

	printf("type   -> %s\n", lgt_lst[ptr->type]);
	printf("color  -> ");
	fflush(stdout);
	print_bits(&ptr->col, sizeof(ptr->col));
	printf("bright -> %i\n", ptr->bright);
	switch (ptr->type)
	{
		case (LGT_AMBIENT):
			break ;
		case (LGT_POINT):
			t_lgt_pt	*pt;

			pt = (t_lgt_pt *)ptr;
			printf("normal -> x:%f y:%f z:%f\n", pt->pos.x, pt->pos.y, pt->pos.z);
			break ;
		default :
			;
	}
	printf("\n");
}

void	mrt_int_debug_print_obj(t_base_obj *ptr)
{
	if (ptr == NULL)
		return ;

	printf("type   -> %s\n", obj_lst[ptr->type]);
	printf("coord  -> x:%f y:%f z:%f\n", ptr->pos.x, ptr->pos.y, ptr->pos.z);
	printf("color  -> ");
	fflush(stdout);
	print_bits(&ptr->col, sizeof(ptr->col));
	switch (ptr->type)
	{
		case (OBJ_SPHERE):
			t_obj_sph	*sph;

			sph = (t_obj_sph *)ptr;
			printf("diam   -> %f\n", sph->d);
			break ;
		case (OBJ_PLANE):
			t_obj_pln	*pln;

			pln = (t_obj_pln *)ptr;
			printf("normal -> x:%f y:%f z:%f\n", pln->normal.x, pln->normal.y, pln->normal.z);
			break ;
		case (OBJ_CYLINDER):
			t_obj_cyl	*cyl;

			cyl = (t_obj_cyl *)ptr;
			printf("axis   -> x:%f y:%f z:%f\n", cyl->axis.x, cyl->axis.y, cyl->axis.z);
			break ;
		default :
			;
	}
	printf("\n");
}
