in vec4 P;
in vec3 N;
in vec4 color;

in vec4 worldCoord;
in float H;

vec4 phongIllumination(vec4 P, vec3 N) {
	// Transform the vertex position
	//gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex;

	// Ambient calculation
	vec4 ambient = gl_FrontMaterial.ambient * gl_LightModel.ambient;

	// Emission calculation
	vec4 emission = gl_FrontMaterial.emission;

	// Diffuse calculation
	//vec4 P = gl_ModelViewMatrix * gl_Vertex;
	//vec3 N = normalize(gl_NormalMatrix * gl_Normal);

	vec3 L = normalize(gl_LightSource[0].position.xyz - vec3(P * gl_LightSource[0].position.w));
	float diffuseIntensity = max(dot(N, L), 0);
	vec4 diffuse = gl_FrontMaterial.diffuse * gl_LightSource[0].diffuse * diffuseIntensity;

	// Specular calculation
	vec3 R = normalize(reflect(L, N));
	vec3 V = normalize(P.xyz);
	float specularIntensity = pow(max(dot(R, V), 0), .16 * gl_FrontMaterial.shininess); //was .2* 
	vec4 specular = gl_FrontMaterial.specular * gl_LightSource[0].specular * specularIntensity;

	//return clamp(ambient + emission + diffuse + specular, 0, 1);// *vec4(1, H, 1, 1);
	//return vec4(N, 1); //this is beautiful. 
	/*if (H >= 0) {
		return vec4(1, 1, H, 1);
	}
	else {
		return vec4(1, 1, 1, 1);
	}*/
	return vec4(1, 1, H, 1);// *clamp(ambient + emission + diffuse + specular, 0, 1, );

	//return clamp(ambient + emission + diffuse + specular, H, 1);// *vec4(1, 1, 1, H); //kinda shitty blending on the snow but whatever
}

void main()
{
    // Do Nothing
	//phongIllumination(vec4 P, vec3 N);
	//gl_FragColor = orenNayarIllum(P, N); //phongIllumination(P, N); //color;
	gl_FragColor = phongIllumination(P, N); //color;
}