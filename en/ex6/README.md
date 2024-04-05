For the needs of taxi transport applications such as Uber, it is necessary to implement a module for managing drivers and transports.

Implement a class Vehicle in which the following information is stored:


The registration number of the vehicle (array of 8 characters)
Driver's name (dynamically allocated array of characters)
Location - the area where the vehicle is currently located (integer)
Maximum number of passengers that can be carried in one trip (integer)
Number of kilometers traveled by the vehicle (decimal number, initially zero)
For the class, implement:

the necessary constructors,
operator= and methods for the solution to function. (10 points).
operator<< for printing information about the vehicle. (5 points)
operator== for comparing two vehicles based on their registration numbers.
operator+= for increasing the number of kilometers traveled by X km
Implement a class RideApp in which the following information is stored:

Name of the application (array of up to 20 characters)
List of vehicles that operate through this application (dynamically allocated array of objects of class Vehicle, initially without elements)
Number of vehicles (number of elements in the array of drivers - integer, initially 0)
For the class, implement the necessary constructors and methods in order for the solution to function. (5 points) Additionally, implement in the class:

operator+= to add a new vehicle to the application. (10 points)
A vehicle can only appear once in the application, so adding a vehicle with an already existing registration number should not be allowed. (5 points)
method void addRide(int area, int passengers, int distanceKm) - to assign transport to the vehicle that is closest to the area area and that can transport at least passenger number of passengers. The following rules apply when assigning transport to a vehicle:
The space where the application operates is divided into 10 adjacent areas. For example, if the passengers are in area 5, first check if there is an available vehicle in that same area (5), then if there are vehicles in the first adjacent areas (4 and 6), then in the second adjacent areas (3 and 7), etc.
If there are multiple available vehicles in the area closest to the desired area, the vehicle that has traveled the fewest kilometers so far is chosen.
Once the transport is assigned to the vehicle, its location is changed to the destination area (area) and the number of kilometers traveled is increased by the number of kilometers of the transport (distanceKm). (15 points)
operator<< - for printing information about all vehicles working for the application (format in test examples). (10 points)
Explanation of the second test example:

The application has 4 vehicles managed by Stefan (located in area 2, capacity 3), Vlatko (located in area 3, capacity 5), Stojmenski (located in area 8, capacity 2), and Tenev (located in area 1, capacity 6).

2 4 3

3 4 4

2 2 5

8 3 10



The first ride is requested for area 2 and a vehicle with at least 4 seats is required. Of the 4 vehicles, 2 have a capacity of at least 4 seats (Vlatko and Tenev). Vlatko is closest (1 area away), so this ride is assigned to him. Now his location changes from 3 to 2 and the number of kilometers traveled increases from 0 to 3 (+3).



The second ride is requested for area 3 and a vehicle with at least 4 seats is required. Of the 4 vehicles, 2 have a capacity of at least 4 seats (Vlatko and Tenev). Vlatko is closest (1 area away), so this ride is assigned to him. Now his location changes from 2 to 3 and the number of kilometers traveled increases from 3 to 7 (+4).



The third ride is requested for area 2 and a vehicle with at least 2 seats is required. All 4 vehicles meet this condition. Stefan is closest (0 areas away), so this ride is assigned to him. Now his location changes from 3 to 2 and the number of kilometers traveled increases from 0 to 5 (+5).



The fourth ride is requested for area 8 and a vehicle with at least 3 seats is required. Of the 4 vehicles, 3 have a capacity of at least 3 seats (Stefan, Vlatko, and Tenev). Vlatko is closest (5 areas away), so this ride is assigned to him. Now his location changes from 3 to 8 and the number of kilometers traveled increases from 7 to 17 (+10).