#include <glad/glad.h>
#include <stb/stb_image.h>

#include <filesystem>
namespace  std {
	namespace filesystem = experimental::filesystem::v1;
};

#include <string>


class Texture
{
public:
	Texture()
	{

	}
	
	virtual ~Texture()
	{
	}

	bool load(const std::string& texture_path)
	{
		std::filesystem::path path = texture_path;
		path = std::filesystem::absolute(path);

		auto abs_path = path.u8string();

		// load texture using stb lib
		stbi_set_flip_vertically_on_load(true);

		int width, height, nrChannels;
		unsigned char *data = stbi_load(abs_path.c_str(), &width, &height, &nrChannels, 0);

		if (!data)
			return false;

		// create texture
		glGenTextures(1, &m_texture_id);
		glBindTexture(GL_TEXTURE_2D, m_texture_id);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		if (nrChannels == 3)
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		else
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}

	void active(unsigned int texture_unit = 0) const
	{
		if (m_texture_id)
		{
			// OpenGL should have a at least a minimum of 16 texture units for you to use which you can activate
			// using GL_TEXTURE0 to GL_TEXTURE15. They are defined in order so we could also get GL_TEXTURE8 via
			// GL_TEXTURE0 + 8 for example, which is useful when we'd have to loop over several texture units.
			glActiveTexture(GL_TEXTURE0 + texture_unit); // activate the texture unit first before binding texture
			glBindTexture(GL_TEXTURE_2D, m_texture_id);
		}
	}
private:
	unsigned int m_texture_id{ 0 };
};

