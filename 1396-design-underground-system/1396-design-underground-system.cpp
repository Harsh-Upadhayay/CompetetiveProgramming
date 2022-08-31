class UndergroundSystem {
public:
    
    map<int, pair<string, int>> in;
    map<pair<string, string>, vector<int>> avg;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        in[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        avg[{in[id].first, stationName}].push_back( t - in[id].second);
        in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
        int sum = 0;
        for(auto i : avg[{startStation, endStation}])
            sum += i;
        return sum / (double) avg[{startStation, endStation}].size();
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */