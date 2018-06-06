#ifndef MESH_H
#define MESH_H
#include <Vector>
#include <GL/glew.h>
#include "Vector.h"
#include "Matrix.h"


using namespace MATH;

struct Vertices
{
	std::vector<Vec3> pos;
	std::vector<Vec3> normal;
	std::vector<Vec2> uvCoord;
	std::vector<Vec4> color;

	Vertices(std::vector<Vec3> Pos, std::vector<Vec3> norm, std::vector<Vec2> uv, std::vector<Vec4> col) : pos(Pos), normal(norm), uvCoord(uv), color(col){}
	Vertices(std::vector<Vec3> Pos, std::vector<Vec3> norm, std::vector<Vec2> uv): pos(Pos), normal(norm), uvCoord(uv){}
};

class Mesh {
    public:
		Vertices vertices;
        std::vector<GLuint> indices; 
		GLenum drawmode;
      
        Mesh(GLenum drawmode_, Vertices vertices);
        void Render() const;
    private: 
        GLuint vao, vbo;
        void setupMesh();
};  

#endif