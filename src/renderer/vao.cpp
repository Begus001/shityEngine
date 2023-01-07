#include <renderer/vao.h>


namespace se
{

VBOLayout::VBOLayout() : mStride(0) {}

std::vector<VBOAttribute> VBOLayout::getAttributes() const
{
	return mAttributes;
}

unsigned int VBOLayout::getStride() const
{
	return mStride;
}

template<>
void VBOLayout::push<float>(unsigned int count, bool normalized)
{
	mAttributes.push_back({ GL_FLOAT, count, normalized });
	mStride += sizeof(GLfloat) * count;
}

VAO::VAO()
{
	GLCALL(glGenVertexArrays(1, &mID));
	GLCALL(glBindVertexArray(mID));
}

VAO::~VAO()
{
	GLCALL(glDeleteVertexArrays(1, &mID));
}

void VAO::bind() const
{
	GLCALL(glBindVertexArray(mID));
}

void VAO::unbind() const
{
	GLCALL(glBindVertexArray(0));
}

void VAO::addVBO(const VBO &vbo, const VBOLayout &layout)
{
	bind();
	vbo.bind();

	const auto &attribs = layout.getAttributes();

	size_t offset = 0;

	for (unsigned int i = 0; i < attribs.size(); i++) {
		auto &attrib = attribs[i];

		GLCALL(glVertexAttribPointer(i, attrib.count, attrib.type, attrib.normalized ? GL_TRUE : GL_FALSE, layout.getStride(), (void *)offset));

		GLCALL(glEnableVertexAttribArray(i));

		offset += sizeof(attrib.type) * attrib.count;
	}
}

unsigned int VAO::getID() const
{
	return mID;
}

}