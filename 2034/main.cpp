class StockPrice {
public:
  unordered_map<int,int> prices;
  priority_queue<pair<int,int>> min_pq, max_pq;
  int latest;

  StockPrice() {

  }

  void update(int timestamp, int price) {
    latest = max(latest, timestamp);
    prices[timestamp] = price;
    min_pq.push({-price, timestamp});
    while(prices[min_pq.top().second] != -min_pq.top().first) min_pq.pop();
    max_pq.push({price, timestamp});
    while(prices[max_pq.top().second] != max_pq.top().first) max_pq.pop();
  }

  int current() {
    return prices[latest];
  }

  int maximum() {
    return max_pq.top().first;
  }

  int minimum() {
    return -min_pq.top().first;
  }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
