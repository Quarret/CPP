#include <bits/stdc++.h>
using ll = long long;
using namespace std;

class MovieRentingSystem {
    unordered_map<int,priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>> notRentMovie;
    unordered_map<int, unordered_set<int>> shop_to_movie;
    unordered_map<int, unordered_map<int, int>> shopAndMovie_to_Price;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> RentMovie;
public:
    int N;
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        N = n;
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];

            // 初始化时, 电影都未出租
            notRentMovie[movie].emplace(price, shop);

            // 每个商店有那些电影
            shop_to_movie[shop].insert(movie);

            // 标价
            shopAndMovie_to_Price[shop][movie] = price;
        }
    }
    
    vector<int> search(int movie) {
        // 在未出租的电影中找, 懒删除
        vector<int> ans;
        auto pq = notRentMovie[movie];
        vector<int> vis(N);
        
        while (!pq.empty()) {
            if (ans.size() == 5) break;

            auto [price, shop] = pq.top();
            pq.pop();

            // 该商店里的movie已被借走
            if (!shop_to_movie[shop].count(movie) || vis[shop]) continue;

            // 商店有该movie
            vis[shop] = 1;
            ans.push_back(shop);
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        // 从商店中删去movie
        shop_to_movie[shop].erase(movie);

        // 获取价格
        int price = shopAndMovie_to_Price[shop][movie];

        // 将movie加入Rent
        RentMovie.emplace(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
        // 商店获得movie
        shop_to_movie[shop].insert(movie);

        // 获取价格
        int price = shopAndMovie_to_Price[shop][movie];

        // 将movie加入notRent
        notRentMovie[movie].emplace(price, shop);        
    }
    
    vector<vector<int>> report() {
        // 在未出租的电影中找, 懒删除
        vector<vector<int>> ans;
        unordered_map<int, unordered_map<int, int>> vis;
        
        while (!RentMovie.empty()) {
            if (ans.size() == 5) break;

            auto [price, shop, movie] = RentMovie.top();
            RentMovie.pop();

            // 该商店里的movie未被借走 懒删除
            if (shop_to_movie[shop].count(movie) || vis[shop][movie]) continue;
            vis[shop][movie] = 1;

            // 商店没有该movie
            ans.push_back({shop, movie});
        }

        return ans;
    }
};


// 少用优序队列, 尤其是要与hash结合的时候, 这种设计题都不想调试了
class MovieRentingSystem {
    unordered_map<long long, int> shop_movie_to_price;
    unordered_map<int, set<pair<int, int>>> unrented_movie_to_shop;
    set<tuple<int, int, int>> rented_movies;// (price, shop, movie)
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            // shop 与 moive一起组成hashkey
            shop_movie_to_price[1LL * shop << 32 | movie] = price;
            unrented_movie_to_shop[movie].emplace(price, shop);
        }
    }
    
    vector<int> search(int movie) {
        auto it = unrented_movie_to_shop.find(movie);
        if (it == unrented_movie_to_shop.end()) return {};

        vector<int> ans;
        for (auto &[_, shop] : it -> second) {
            ans.push_back(shop);
            if (ans.size() == 5) {
                break;
            }
        }

        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = shop_movie_to_price[1LL * shop << 32 | movie];
        unrented_movie_to_shop[movie].erase({price, shop});
        rented_movies.emplace(price, shop, movie);
    }
    
    void drop(int shop, int movie) {
        int price = shop_movie_to_price[1LL * shop << 32 | movie];
        unrented_movie_to_shop[movie].emplace(price, shop);
        rented_movies.erase({price, shop, movie});    
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;

        for (auto &[_, shop, movie] : rented_movies) {
            ans.push_back({shop, movie});

            if (ans.size() == 5) {
                break;
            }
        }

        return ans;
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    

    return 0;
}
