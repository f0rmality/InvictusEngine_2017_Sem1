#include "Mesh.h"

using namespace MATH;

Mesh::Mesh(GLenum drawmode_, Vertices vertices_) : vertices(vertices_){
	drawmode = drawmode_;
    this->setupMesh();
}

void Mesh::setupMesh() {
	#define VERTEX_LENGTH 	(vertices.pos.size() * (sizeof(Vec3)))
	#define NORMAL_LENGTH 	(vertices.normal.size() * (sizeof(Vec3)))
	#define TEXCOORD_LENGTH (vertices.uvCoord.size() * (sizeof(Vec2)))
	#define COLOR_LENGTH	(vertices.color.size() * (sizeof(Vec4)))
	
    /// Create and initialize vertex buffer object VBO
    glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
    glGenBuffers(1, &vbo );
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH + COLOR_LENGTH, NULL, GL_STATIC_DRAW );

	 /// assigns the addr of "points" to be the beginning of the array buffer "sizeof(points)" in length
    glBufferSubData(GL_ARRAY_BUFFER, 0, VERTEX_LENGTH, &vertices.pos[0] );
	/// assigns the addr of "normals" to be "sizeof(points)" offset from the beginning and "sizeof(normals)" in length  
    glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH, NORMAL_LENGTH, &vertices.normal[0] );
	/// assigns the addr of "texCoords" to be "sizeof(points) + sizeof(normals)" offset from the beginning and "sizeof(texCoords)" in length  
    glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH + NORMAL_LENGTH , TEXCOORD_LENGTH , &vertices.uvCoord[0]);
	///assigns the addr of "color" to be "sizeof...............blablabla
	glBufferSubData(GL_ARRAY_BUFFER, VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH, COLOR_LENGTH, &vertices.color[0]);
	
	int verticiesID = 0;
	int normalsID = 1;
	int uvCoordsID = 2;
	int colorID = 3;

	glEnableVertexAttribArray(verticiesID);
	glVertexAttribPointer(verticiesID, 3, GL_FLOAT, GL_FALSE, 0,(GLvoid*)(0) );
	glEnableVertexAttribArray(normalsID);
	glVertexAttribPointer(normalsID, 3, GL_FLOAT, GL_FALSE, 0,(GLvoid*)(VERTEX_LENGTH) );
	glEnableVertexAttribArray(uvCoordsID);
	glVertexAttribPointer(uvCoordsID, 2, GL_FLOAT, GL_FALSE, 0,(GLvoid*)(VERTEX_LENGTH + NORMAL_LENGTH) );
	glEnableVertexAttribArray(colorID);
	glVertexAttribPointer(colorID, 4, GL_FLOAT, GL_FALSE, 0, (GLvoid*)(VERTEX_LENGTH + NORMAL_LENGTH + TEXCOORD_LENGTH));


	glBindBuffer(GL_ARRAY_BUFFER,0); /// Unbinds the buffer by setting it to zero   
	glBindVertexArray(0); // Disable the VBO  
	glEnableVertexAttribArray(0); // Disable the VAO

	#undef VERTEX_LENGTH
	#undef NORMAL_LENGTH
	#undef TEXCOORD_LENGTH
	#undef COLOR_LENGTH
}  


void Mesh::Render() const{
	glBindVertexArray(vao);
	glDrawArrays(drawmode, 0, vertices.pos.size());
	glEnableVertexAttribArray(0); // Disable the VAO
}
