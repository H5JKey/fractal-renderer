#version 460


uniform vec2 u_resolution;
uniform vec2 u_center;
uniform float u_zoom;

out vec4 fragColor;

vec2 multiply(vec2 a, vec2 b) {
    return vec2(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x);
}


void main()
{
    vec2 uv = (2.0*gl_FragCoord.xy-u_resolution.xy)/u_resolution.y;

    vec2 c = uv/u_zoom + u_center;

    const int iterations = 300;
    const float R = 2.0;
    vec2 z = vec2(0,0);

    int i;
    for (i=0; i<iterations; i++) {
        z = multiply(z,z)+c;
        if (dot(z,z) > R*R) break;
    }

    if (i == iterations) {
        fragColor = vec4(0.0, 0.0, 0.0, 1.0);
    } else {
        float t = float(i) - log2(log2(dot(z, z))) + 4.0;
        t = t / float(iterations);
        
        float r = 0.5 + 0.5 * cos(6.28318 * t + 0.0);
        float g = 0.5 + 0.5 * cos(6.28318 * t + 2.094);
        float b = 0.5 + 0.5 * cos(6.28318 * t + 4.188);
        
        fragColor = vec4(r, g, b, 1.0);
    }
}