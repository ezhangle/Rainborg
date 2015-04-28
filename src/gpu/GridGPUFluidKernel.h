#ifndef __GRID_GPU_FLUID_KERNEL_H__
#define __GRID_GPU_FLUID_KERNEL_H__

#include "../FluidBoundingBox.h"
#include "../FluidVolume.h"
#include "../MathDefs.h"

typedef struct {
  Vector3s pos;
  Vector3s vec1;
  Vector3s vec2;
  Vector3s vec3;
  scalar sca1;
  scalar sca2;
  scalar sca3;
} grid_gpu_block_t;

extern "C" {
  void grid_initGPUFluid(int **g_neighbors, int **g_gridIndex,
                         int **g_grid,
                         int **g_gridUniqueIndex, int **g_partUniqueIndex,
                         grid_gpu_block_t **g_particles,
                         FluidVolume* h_volumes, int num_volumes,
                         FluidBoundingBox* h_boundingbox,
                         scalar h);

  void grid_stepFluid(int **g_neighbors, int **g_gridIndex,
                      int **g_grid,
                      int **g_gridUniqueIndex, int **g_partUniqueIndex,
                      grid_gpu_block_t **g_particles,
                      int num_particles,
                      FluidBoundingBox* h_boundingbox,
                      scalar h,
                      Vector3s accumForce,
                      scalar dt);

  void grid_updateVBO(float *vboptr, grid_gpu_block_t *g_particles, int num_particles);
}
#endif