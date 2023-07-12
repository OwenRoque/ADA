// aun no funciona
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left;
    int right;
};

bool compareSegments(const Segment& seg1, const Segment& seg2) {
    return seg1.left < seg2.left;
}

vector<Segment> divideAndConquer(vector<Segment>& segments, int M) {
    vector<Segment> solution;

    if (segments.empty() || M <= 0) {
        return solution;
    }

    if (segments.size() == 1 && segments[0].left <= 0 && segments[0].right >= M) {
        solution.push_back(segments[0]);
        return solution;
    }

    vector<Segment> segmentsBeforeM;
    vector<Segment> segmentsAfterM;

    for (const auto& segment : segments) {
        if (segment.left <= 0 && segment.right >= M) {
            solution.push_back(segment);
        } else if (segment.left < M) {
            segmentsBeforeM.push_back(segment);
        } else {
            segmentsAfterM.push_back(segment);
        }
    }

    if (solution.empty()) {
        sort(segmentsBeforeM.begin(), segmentsBeforeM.end(), compareSegments);
        solution = divideAndConquer(segmentsBeforeM, M);

        if (!segmentsAfterM.empty()) {
            vector<Segment> solutionAfterM = divideAndConquer(segmentsAfterM, M);

            if (!solutionAfterM.empty()) {
                solution.insert(solution.end(), solutionAfterM.begin(), solutionAfterM.end());
            }
        }
    }

    return solution;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int M;
        cin >> M;

        vector<Segment> segments;
        Segment segment;

        while (cin >> segment.left >> segment.right && (segment.left != 0 || segment.right != 0)) {
            segments.push_back(segment);
        }

        vector<Segment> solution = divideAndConquer(segments, M);

        if (solution.empty()) {
            cout << "0" << endl;
        } else {
            cout << solution.size() << endl;

            for (const auto& seg : solution) {
                cout << seg.left << " " << seg.right << endl;
            }
        }

        if (T > 0) {
            cout << endl;  // Imprimir línea en blanco entre los casos de prueba
        }
    }

    return 0;
}