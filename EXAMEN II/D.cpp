#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right;
};

bool compareSegments(const Segment& seg1, const Segment& seg2) {
    return seg1.left < seg2.left;
}

vector<Segment> minimalCoverage(vector<Segment>& segments, int start, int end, int M) {
    vector<Segment> result;

    // Caso base: no hay segmentos o el rango es menor o igual a cero
    if (start >= end || M <= 0) {
        return result;
    }

    int maxRight = -1;
    int maxRightIndex = -1;

    // Encontrar el segmento con el punto de fin más lejano dentro del rango [start, end)
    for (int i = start; i < end; i++) {
        if (segments[i].left <= M && segments[i].right > maxRight) {
            maxRight = segments[i].right;
            maxRightIndex = i;
        }
    }

    // Comprobar si el segmento seleccionado cubre todo el rango [0, M]
    if (maxRight >= M) {
        // Agregar el segmento seleccionado a la solución
        result.push_back(segments[maxRightIndex]);

        // Resolver recursivamente los subproblemas izquierdo y derecho
        vector<Segment> leftResult = minimalCoverage(segments, start, maxRightIndex, segments[maxRightIndex].left);
        vector<Segment> rightResult = minimalCoverage(segments, maxRightIndex + 1, end, M - maxRight);

        // Combinar las soluciones de los subproblemas
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
    }
    return result;
}

int main() {
    int testCases;
    cin >> testCases;

    while (testCases--) {
        int M;
        cin >> M;

        vector<Segment> segments;
        int left, right;

        while (cin >> left >> right) {
            if (left == 0 && right == 0) {
                break;
            }

            segments.push_back({ left, right });
        }

        sort(segments.begin(), segments.end(), compareSegments);

        vector<Segment> result = minimalCoverage(segments, 0, segments.size(), M);

        if (result.empty()) {
            cout << "0" << endl;
        } else {
            cout << result.size() << endl;
            for (const Segment& seg : result) {
                cout << seg.left << " " << seg.right << endl;
            }
        }

        if (testCases > 0) {
            cout << endl;
        }
    }

    return 0;
}
