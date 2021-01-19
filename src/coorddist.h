#pragma once

#include <cmath>

/**
 * @brief Utility function for converting degrees to radians
 *
 * @param degree Angle in degrees
 * @return Angle in radians
 */
long double toRadians(const long double degree);

/**
 * @brief Function for finding the distance between two points on the earth,
 * given their latitudes and longitudes in degrees
 *
 * @param lat1  The latitude of the first point in degrees
 * @param long1 The longitude of the first point in degrees
 * @param lat2  The latitude of the second point in degrees
 * @param long2 The longitude of the second point in degrees
 *
 * @return Great-circle distance (shortest distance between the points)
 */
long double distance(long double lat1, long double long1, long double lat2, long double long2);
