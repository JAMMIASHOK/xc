XC meshing is based on multi-block meshes. Multi-block means that the block topology can be made from multiply connected blocks. Each block is composed of 3D hexahedral, 2D quadrilateral, and 1D elements arranged in rows, columns, and layers. The multi-block structure allows a great amount of control over the design of the mesh.

This directory contains the classes used to define multi-block topology as follows:

- **entities**: geometric entities (points, lines, surfaces, volumes).
- **trf**: transformation of geometric entities (translation, rotation, scaling, reflection).
- **matrices**: arrays of points, nodes and elements arranged in rows, columns, and layers.
