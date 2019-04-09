// Copyright [2019] <Jichun Li> [copyright]
// CSE 333  Spring 2019
// ex3
// jichunli@uw.edu

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// define the struct Point3D
typedef struct point3d_st {
    int32_t x;
    int32_t y;
    int32_t z;
} Point3d, *Point3dPtr;

Point3d* AllocatePoint3d(int32_t x, int32_t y, int32_t z);

int main(int argc, char** argv) {
    // original coordinates of points
    int32_t x = 1;
    int32_t y = 2;
    int32_t z = 3;

    // Allocate memory for Point3D struct
    Point3d* point_3d_ptr = AllocatePoint3d(x, y, z);

    if (point_3d_ptr == NULL) {     // allocation failed
        printf("ERROR: Memory allocation failed\n");
        free(point_3d_ptr);
        point_3d_ptr = NULL;
        return EXIT_FAILURE;
    } else if (point_3d_ptr->x == 1 && point_3d_ptr->y == 2 &&
            point_3d_ptr->z == 3) {   // ptr is not null and fields match
        printf("Allocation suceeded\n");
        free(point_3d_ptr);
        point_3d_ptr = NULL;
        return EXIT_SUCCESS;
    } else {    // ptr is not null but fields are different
        printf("ERROR: Fields do not match\n");
        free(point_3d_ptr);
        point_3d_ptr = NULL;
        return EXIT_FAILURE;
    }
}

// The function of allocating memory for Point3D
// accepts 3 int32_t values are x, y, z fields of Point3D
Point3d* AllocatePoint3d(int32_t x, int32_t y, int32_t z) {
    Point3d* retval = (Point3d*) malloc(sizeof(Point3d));
    if (retval != NULL) {   // test if the allocation succeeds
        retval->x = x;
        retval->y = y;
        retval->z = z;
    }
    return retval;
}
