#!/bin/sh
#!/bin/bash

#SBATCH --job-name=tflojob
#SBATCH --partition=Centaurus
#SBATCH --time=00:20:00
#SBATCH --nodes=1
#SBATCH --tasks-per-node=16

OMP_NUM_THREADS=1 ./pi 
OMP_NUM_THREADS=2 ./pi 
OMP_NUM_THREADS=4 ./pi  

