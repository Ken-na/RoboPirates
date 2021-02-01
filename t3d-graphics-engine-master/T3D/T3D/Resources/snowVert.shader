varying out vec4 P;
varying out vec3 N;

varying out vec4 color;
varying out float H;

varying out vec4 worldCoord;



void main()
{
	// Transform the vertex position
	gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

	// Calc position and normal, light direction and view direction
	P = gl_ModelViewMatrix * gl_Vertex;
	N = normalize(gl_NormalMatrix * gl_Normal);

	//gl_FragCoord.xyz = gl_Position.xyz / gl_Position.w;
	//gl_FragCoord.w = 1 / gl_Position.w;
	worldCoord = gl_ModelViewMatrix * gl_Vertex;

	/*vec2 screen = (vec2(gl_FragCoord.x, gl_FragCoord.y) - viewport.xy) * viewport.zw;
	float depth = texture2D(DepthTexture, screen).x;
	vec4 world = vec4(screen, depth, 1.0) * IM;
	world.xyz /= world.w;*/

	H = gl_Vertex.y; //ok we are getting there....
	//P.y ;
	//H = gl_Position.y;

	//color = phongIllumination(P, N);
	//color = vec4(N, 1); //this is beautiful. 
	//worldCoord = ViewMatrixInverse * gl_Position;
	//color = vec4(1, gl_Normal.y, 1, 1);

	/*vec4 worldPosition = modelMatrix * vec4(position, 1.0);

	// Position in normalized screen coords: ADD CAMERA
	gl_Position = projectionMatrix * viewMatrix * worldPosition;

	// Here you can compute the color based on worldPosition, for example:
	vColor = normalize(abs(worldPosition.y));*/
}
