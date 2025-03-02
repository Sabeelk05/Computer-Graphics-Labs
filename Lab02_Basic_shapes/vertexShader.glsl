#version 330 core 

layout(location = 0) in vec3 position;
layout(location = 1) in vec3 colours;

out vec3 fragmentColour;
void main(){
	//Output the vertex position
	gl_Position = vec4(position, 1.0);

	//output fragment colour
	fragmentColour = colours;
}