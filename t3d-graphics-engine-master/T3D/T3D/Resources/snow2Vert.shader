varying out vec4 P;
varying out vec3 N;
varying out vec3 H;



void main()
{
	// Transform the vertex position
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

	// Calc position and normal, light direction and view direction
	P = gl_ModelViewMatrix * gl_Vertex;
	N = normalize(gl_NormalMatrix * gl_Normal);
	
	//H = gl_Position.y;// gl_Vertex.y;
	H = gl_Vertex;
	
	//color = phongIllumination(P, N);
}
