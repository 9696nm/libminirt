
#include "minirt_int.h"

static const char	*cam_lst[] = {"PERSPECTIVE", "UNKNOWN"};
static const char	*lgt_lst[] = {"AMBIENT", "POINT", "UNKNOWN"};
static const char	*obj_lst[] = {"SPHERE", "PLANE", "CYLINDER", "UNKNOWN"};

void	mrt_int_debug_print_cam(t_base_cam *ptr)
{
	t_cam_persp	*persp;

	if (ptr == NULL)
		return ;

	printf("type   -> %s\n", cam_lst[ptr->type]);
	printf("coord  -> x:%f y:%f z:%f\n", ptr->pos.x, ptr->pos.y, ptr->pos.z);
	printf("view   -> x:%f y:%f z:%f\n", ptr->view.x, ptr->view.y, ptr->view.z);
	switch (ptr->type)
	{
		case (CAM_PERSPECTIVE):
			persp = (t_cam_persp *)ptr;
			printf("fov    -> %i\n", persp->fov);
			printf("fov_tan-> %f\n", persp->focal_length);
			printf("cam_rot-> x:%f y:%f z:%f w:%f\n",
				persp->cam_rot.x, persp->cam_rot.y, persp->cam_rot.z, persp->cam_rot.w);
			break ;
		default :
			;
	}
	printf("\n");
}

void	mrt_int_debug_print_lgt(t_base_lgt *ptr)
{
	t_lgt_pt	*pt;

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
	t_obj_sph	*sph;
	t_obj_pln	*pln;
	t_obj_cyl	*cyl;

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
			sph = (t_obj_sph *)ptr;
			printf("diam   -> %f\n", sph->d);
			printf("radius -> %f\n", sph->r);
			break ;
		case (OBJ_PLANE):
			pln = (t_obj_pln *)ptr;
			printf("normal -> x:%f y:%f z:%f\n", pln->normal.x, pln->normal.y, pln->normal.z);
			break ;
		case (OBJ_CYLINDER):
			cyl = (t_obj_cyl *)ptr;
			printf("axis   -> x:%f y:%f z:%f\n", cyl->axis.x, cyl->axis.y, cyl->axis.z);
			break ;
		default :
			;
	}
	printf("\n");
}
