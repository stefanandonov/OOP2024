#include<iostream>
#include<cstring>

using namespace std;

/*
YOUR CODE HERE
DO NOT MODIFY THE FUNCTIONS BELOW!!!
*/

class Post {
protected:
    string username;
    string content;
    bool hasPhoto;
    int likes;
public:

    Post(const string &username, const string &content, bool hasPhoto, int likes) : username(username),
                                                                                    content(content),
                                                                                    hasPhoto(hasPhoto),
                                                                                    likes(likes) {}

    virtual double popularity() const = 0;

    virtual void print() = 0;

    bool operator<(const Post &rhs) const {
        return popularity() < rhs.popularity();
    }

    bool operator>(const Post &rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Post &rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Post &rhs) const {
        return !(*this < rhs);
    }

    friend double mostPopularPostWithPhoto(Post **posts, int n);
};

class FacebookPost : public Post {
private:
    int shares;
public:
    FacebookPost(const string &username, const string &content, bool hasPhoto, int likes, int shares) : Post(username,
                                                                                                             content,
                                                                                                             hasPhoto,
                                                                                                             likes),
                                                                                                        shares(shares) {}

    double popularity() const override {
        double result = likes * shares;

        if (hasPhoto) {
            result *= 1.2;
        }

        return result;
    }

    void print() override {
        cout << "Facebook post" << endl;
        cout << "Username: " << username << endl;
        cout << "Content: " << content << endl;
        if (hasPhoto) {
            cout << "With photo" << endl;
        } else {
            cout << "Without photo" << endl;
        }

        cout << "Likes: " << likes << " Shares: " << shares << endl;
        cout << "Popularity: " << popularity() << endl;
    }

    friend FacebookPost *fbPostWithMaxShares(Post **posts, int n);
};

class TwitterPost : public Post {
private:
    int retweets;
    int replies;
public:
    TwitterPost(const string &username, const string &content, bool hasPhoto, int likes, int retweets, int replies)
            : Post(username, content, hasPhoto, likes), retweets(retweets), replies(replies) {}

    double popularity() const override {
        double result = likes * retweets * replies;

        if (hasPhoto) {
            result *= 1.1; //10%
        }

        if (content.find("#crypto") != -1) {
            result *= 1.2; //20%
        }

        return result;
    }

    void print() override {
        cout << "Twitter post" << endl;
        cout << "Username: " << username << endl;
        cout << "Content: " << content << endl;
        if (hasPhoto) {
            cout << "With photo" << endl;
        } else {
            cout << "Without photo" << endl;
        }

        cout << "Likes: " << likes << " Retweets: " << retweets << " Replies: " << replies << endl;
        cout << "Popularity: " << popularity() << endl;
    }
};

Post *readFbPost() {
    string username;
    string content;
    bool photo;
    int likes;
    int shares;
    cin.ignore();
    getline(std::cin, username);
    getline(std::cin, content);
    cin >> photo >> likes >> shares;
    return new FacebookPost(username, content, photo, likes, shares);
}

Post *readTwPost() {
    string username;
    string content;
    bool photo;
    int likes;
    int retweets;
    int replies;
    cin.ignore();
    getline(std::cin, username);
    getline(std::cin, content);
    cin >> photo >> likes >> retweets >> replies;
    return new TwitterPost(username, content, photo, likes, retweets, replies);
}

Post **readMultiplePosts(int *n) {

    cin >> *n;
    Post **posts = new Post *[*n];
    for (int i = 0; i < *n; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            posts[i] = readFbPost();
        } else {
            posts[i] = readTwPost();
        }
    }
    return posts;
}

double mostPopularPostWithPhoto(Post **posts, int n) {
    double max = -1;
    for (int i = 0; i < n; i++) {
        if (posts[i]->hasPhoto && posts[i]->popularity() > max) {
            max = posts[i]->popularity();
        }
    }
    return max;
}

FacebookPost *fbPostWithMaxShares(Post **posts, int n) {
    FacebookPost *result = nullptr;

    for (int i = 0; i < n; i++) {
        FacebookPost *casted = dynamic_cast<FacebookPost *>(posts[i]);
        if (casted) {
            if (result == nullptr || casted->shares > result->shares ) {
                result = casted;
            }
        }
    }

    return result;
}

int main() {
    int testCase;

    cin >> testCase;

    if (testCase == 1) {
        cout << "Test FacebookPost" << endl;
        Post *post = readFbPost();
        cout << "Popularity: " << post->popularity() << endl;
        post->print();
    } else if (testCase == 2) {
        cout << "Test TwitterPost" << endl;
        Post *post = readTwPost();
        cout << "Popularity: " << post->popularity() << endl;
        post->print();
    } else if (testCase == 3) {
        cout << "Test operator >=" << endl;
        int n;
        Post **posts = readMultiplePosts(&n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j) {
                    if ((*posts[i]) >= (*posts[j])) {
                        cout << i << " >= " << j << endl;
                    } else {
                        cout << i << " < " << j << endl;
                    }
                }
            }
        }
    } else {
        int n;
        Post **posts = readMultiplePosts(&n);
        for (int i = 0; i < n; i++) {
            posts[i]->print();
            cout << endl;
        }
        cout << "The most popular post with photo has a popularity of: " << mostPopularPostWithPhoto(posts, n) << endl;
        cout << "The facebook post with most shares is ";
        fbPostWithMaxShares(posts,n)->print();
    }

    return 0;
}