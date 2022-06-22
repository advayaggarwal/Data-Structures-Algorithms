//Time complexity - O(1)
//Space complexity - O(n+m), where n is no. of passengersArrivals we have & m is no. of routeAverage we have
class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap; // id, {station, checkin Time}
    unordered_map<string, pair<int, int>> routeMap; // route(startStation + " " + endStation), {totalTime, number of trips}
    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t)
    {
        checkInMap[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto checkIn = checkInMap[id];
        checkInMap.erase(id); //passenger checked out, no need to have in checkInMap, saves space

        string route = checkIn.first + " " + stationName;
        int time = t - checkIn.second;

        routeMap[route].first += time;
        routeMap[route].second += 1;
    }

    double getAverageTime(string startStation, string endStation)
    {
        string route = startStation + " " + endStation;
        return (double)routeMap[route].first / routeMap[route].second;
    }
};