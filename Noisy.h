#pragma once


#include <vector>

namespace IsaacsNoiseLibrary
{

	class Vector2
	{
	public:
		float x;
		float y;

		Vector2();
		Vector2(float x, float y);

		float dot(Vector2 other);

		float distance(Vector2 other);
	};

	class Colour
	{
	public:

		// Black
		Colour();

		// Greyscale
		Colour(float grey);

		// RGB
		Colour(float red, float green, float blue);

		float r, g, b;
	};

	class Pixel
	{
	public:
		Pixel(int x, int y, Colour colour);

		Pixel(Vector2 position, Colour colour);

		Pixel();

		Vector2 position;

		Colour colour;
	};

	class CellularNoise
	{
	public:

		// Cellular Noise with 60 randomised points
		CellularNoise(int width, int height);

		std::vector <Pixel> pixels;

	};

	class FractalNoise
	{
	public:

		std::vector <Pixel> pixels;

		// Returns colour value in 0-255 range
		FractalNoise(int width, int height, float amplitudeScale, float frequencyScale, int octaves);

		float CreateNoise(float x, float y);

	private:

		float colour = 0.0f;

		int permutationTable[256];

		Vector2 gradientTable[256];

	};

	class PerlinNoise
	{

		float colour = 0.0f;

		int permutationTable[256];

		Vector2 gradientTable[256];

		float CreateNoise(float x, float y);
	public:

		// Returns colour values in 0-255 range
		PerlinNoise(float width, float height);

		std::vector <Pixel> pixels;

	};

	class PoissonDistribution
	{

	private:
		// Borders of the Generation
		int minX, minY, maxX, maxY;

		// Minimum distance between two points
		float minRadius;

		// Maximum distance between two points
		float maxRadius;

		// Number of attempts at adding a point
		int attemptCount = 6;

		// Attempt to add a point
		void AddPoint(Vector2 nextPoint);

	public:

		// Access the points generated here
		std::vector <Vector2> points;

		PoissonDistribution(int width, int height);


	};

	class VoronoiNoise
	{
	public:
		// Default with eith random points or poisson for point generation and random colours
		VoronoiNoise(int width, int height, bool usePoisson);

		std::vector <Pixel> pixels;
	};

	inline float Fade(float a)
	{
		return ((6 * a - 15) * a + 10) * a * a * a;
	}

	inline float Lerp(float transformValue, float minValue, float maxValue)
	{
		return minValue + transformValue * (maxValue - minValue);
	}
}