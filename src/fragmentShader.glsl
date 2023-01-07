#version 450 core

out vec4 col;
uniform double test;

bool rtoggle = false;
bool gtoggle = false;
bool btoggle = false;

void main()
{
	double r = mod(test / 2.13456, 1.0);
	double g = mod(test / 2.54365, 1.0);
	double b = mod(test / 2.23491, 1.0);

	if (r >= 0.5) {
		rtoggle = true;
	} else if (r <= 0.0) {
		rtoggle = false;
	}

	if (g >= 0.5) {
		gtoggle = true;
	} else if (g <= 0.0) {
		gtoggle = false;
	}

	if (b >= 0.5) {
		btoggle = true;
	} else if (r <= 0.0) {
		btoggle = false;
	}

	if (!rtoggle) {
		r *= 2;
	} else {
		r = 1.0 - ((r - 0.5) * 2);
	}

	if (!gtoggle) {
		g *= 2;
	} else {
		g = 1.0 - ((g - 0.5) * 2);
	}
	
	if (!btoggle) {
		b *= 2;
	} else {
		b = 1.0 - ((b - 0.5) * 2);
	}

	col = vec4(r, g, b, 1.0f);
}