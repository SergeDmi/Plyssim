# Limesurf
A simulation of the mechanics of a surface as a 2D or 3D set of (visco-) elastic springs.

## Usage

```shell
    $ ./meshless config.yaml
```
In which [config.yaml](config.yaml) is an appropriate config file.

## Installation

Clone/download code in directory `<DIR>` :

 ```shell
    $ git checkout https://github.com/SergeDmi/LimeSurf.git <DIR>
    $ cd <DIR>
    $ git submodule update --init --recursive
```

Then compile in `<DIR>` :
```shell
    $ cd <DIR>
    $ cmake .
    $ make
```

For this you might need to install make, cmake, gcc and the boost libraries. To do so on Ubuntu, use :
```shell
    $ sudo apt-get install make cmake g++
    $ sudo apt-get install libboost-all-dev
```
On a Mac, you can use *brew install* if you are using [Homebrew](https://brew.sh) as your package manager.
On Windows, you can install Ubuntu on a virtual machine, see this [tutorial](https://brb.nci.nih.gov/seqtools/installUbuntu.html) for instance.

## Config file

Config files are yaml type. See [config.yaml](config.yaml) for an example.


### Example
Here is another simple config file

```yaml
meshes:
   first:
       source: demo.ply
       type: 1
       power_law: 2
       prestrain: 1.0
       k_elast: 1.0
       align: 1.0

   another:
       source: demo.ply
       prestrain: 1.1
       k_elast: 1.0
runs:
   deflated:
       duration: 500
       n_frames: 5
       dt: 0.005

       pressure: 0.0
       confinement:
           y:  
               min: -2.2
               max:  2.2
               stiffness: 40
   inflated:
       pressure: 1.0
```
Here, *first*,*another* are two meshes we want to simulate. Each mesh will be simulated in two runs (*deflated* and *inflated*). For meshes and runs, any name will do. Even Meshuggah.

### Options

Here `MESH` and `RUN` are the name specified for a given mesh and run, e.g. `another` is the name of the second mesh, while `deflated` is the name of the first run, in the example above.

#### Meshes

`MESH.source` : source file (ex : *demo.ply*, or *bla/bli/blo.ply*)  
`MESH.type` : type of meshwork (*1*: 2D, *2*: viscous, *3*: 2D+bending, *4*: Tetrahedral 3D mesh)  
`MESH.power_law` : power law of spring elasticity (*1*, *2* or *3*)  
`MESH.prestrain` : prestrain of the springs in the ply file (ex : *1.0* for no prestrain, *1.5* for *50%* prestrain)  
`MESH.k_elast` : sping constant  
`MESH.align` : normal alignment constant  
`MESH.out` : export name

#### Runs

`RUN.duration` : duration of run (in physical time)  
`RUN.n_frames` : number of exported time frames  
`RUN.dt` : simulation timestep  
`RUN.pressure` : pressure in the cell  
`RUN.confinement.AXIS` : Confinement on axis `AXIS=x,y,z`  
`RUN.confinement.AXIS.min` : lower confinement bound  
`RUN.confinement.AXIS.max` : higher confinement bound  
`RUN.confinement.AXIS.stiffness` : confinement stiffness

## Mesh format

Format should be plain text or binary ply files. See [demo.ply](demo.ply) for an example.

## Ouput

The program outputs ply files of the format NAME_RUN_TIME.ply, in which *NAME* is the name of the mesh provided in the config file (or the export name if given), *RUN* is the name of the run, and *T* is the time frame number.

## Misc

### Compiling LimeSurf

LimeSurf compiled succesfully with gcc, clang and icc (see [CMakeLists.txt](CMakeLists.txt)). Fastest executable was found to be with gcc.

# Serge Dmitrieff -- http://biophysics.fr
