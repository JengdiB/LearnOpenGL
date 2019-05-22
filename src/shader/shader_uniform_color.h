#pragma once

namespace shader { namespace uniform_color{

const char* vertext_source = R"(#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec3 aColor;

out vec4 vertexColor;

void main()
{
	gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);

	vertexColor = vec4(aColor, 1.0); 
}
)";

const char* fragment_source = R"(#version 330 core
out vec4 FragColor;

uniform float ourColor; // we set this variable in the OpenGL code.

void main()
{
    FragColor = vec4(0.f, ourColor, 0.f, 1.f); // vec4(1.0f, 1.0f, 0.2f, 1.0f);
}
)";
}
}