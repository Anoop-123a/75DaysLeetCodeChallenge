class Twitter {
     struct Tweet{
            int tweetId;
            int time;

            Tweet(int id ,int t){
                tweetId=id;
                time=t;

            }
     };
    //  we use class when we want to use both function and data member
    //  global time
  int Time;
    // first map -->
    // userId ->Tweets
    unordered_map<int,vector<Tweet>>tweets;
    // second map-->>
    // userId ->userId (userId following)
     unordered_map<int,unordered_set<int>>following;
     
    //  comparator-->>
    class comp{
        public:
           bool operator()(const Tweet&a,const Tweet&b){
               return a.time>b.time;
           }
    };
    


public:
    Twitter() {
           Time=0;

        
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(Tweet(tweetId,Time++));
        
    }
    
    vector<int> getNewsFeed(int userId) {
        // return the tweetId  of 10 most recent tweets done by me or by my following
        // we take of minHeap to track the recent 10 tweets
        priority_queue<Tweet,vector<Tweet>,comp>minHeap;
        // add my tweets-->>
        if(tweets.find(userId)!=tweets.end()){
            auto myTweets=tweets[userId]; //vector of tweets
            for(auto it:myTweets){
               minHeap.push(it);
               if(minHeap.size()>10){
                  minHeap.pop(); //removes the oldest tweet(because the the tweet with maxtime are present at top of minHeap)

               }

            }

        }

        // add tweet from my following-->>
        if(following.find(userId)!=following.end()){
            auto myFollowings=following[userId];
            for(auto followeeId:myFollowings){
             if(tweets.find(followeeId)!=tweets.end()){
             auto followeeTweets=tweets[followeeId]; //vector of tweets
            for(auto it:followeeTweets){
               minHeap.push(it);
               if(minHeap.size()>10){
                  minHeap.pop(); //removes the oldest tweet(because the the tweet with maxtime are present at top of minHeap)

               }

              }  
             }

            }
        }

        // now i will have 10 most recent tweet
        vector<int>newFeedsTweets;
        while(!minHeap.empty()){
            auto [tweetId,time]=minHeap.top();
            minHeap.pop();
            newFeedsTweets.push_back(tweetId);
        }
        reverse(newFeedsTweets.begin(),newFeedsTweets.end());
        return newFeedsTweets;

        
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId==followeeId){
            return ;
        }
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId)!=following.end()){
            following[followerId].erase(followeeId);
        }
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */