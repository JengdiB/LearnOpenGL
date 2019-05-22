#pragma once

namespace shader { namespace simple {
	const char* vertex_source = R"(#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;

out vec4 vertexColor;
out vec2 TexCoord;

uniform float vertexOffset;
uniform mat4 model_transform;
uniform mat4 view_transform;
uniform mat4 projection_transform;
void main()
{
	gl_Position = projection_transform * view_transform * model_transform * vec4(aPos.x + vertexOffset, aPos.y + vertexOffset, aPos.z + vertexOffset, 1.0);

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
uniform float      percentage;
void main()
{
    FragColor = mix(texture(texture_1, TexCoord), texture(texture_2, TexCoord), percentage);
}
)";
}
}
