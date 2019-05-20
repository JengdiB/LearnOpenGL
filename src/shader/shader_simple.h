namespace shader { namespace simple {
const char* vertex_source = R"(#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec4 vertexColor;
out vec2 TexCoord;

uniform vec4 vertexOffset;

void main()
{
	gl_Position = vec4(aPos.x + vertexOffset.y, aPos.y + vertexOffset.y, aPos.z + vertexOffset.y, 1.0);

	vertexColor = gl_Position;
	TexCoord	= aTexCoord;
}
)";

const char* fragment_source = R"(#version 330 core
out vec4 FragColor;

in vec4 vertexColor;
in vec2 TexCoord;

uniform sampler2D texture_1;
uniform sampler2D texture_2;

void main()
{
    FragColor = mix(texture(texture_1, TexCoord), texture(texture_2, TexCoord), 0.2);
}
)";
}
}