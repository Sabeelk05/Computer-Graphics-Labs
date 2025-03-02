#version 330 core 

out vec3 colour;
in vec3 fragmentColour;


void main(){
	colour = fragmentColour;//RGB
}