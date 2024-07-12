import sys
input = sys.stdin.read
from collections import defaultdict

# 입력을 받아 명령어의 개수를 저장합니다.
data = input().split()
numCommands = int(data[0])

# 명령어를 저장할 리스트
intervals = []
currentPosition = 0

# 명령어를 intervals 리스트에 저장합니다.
index = 1
for _ in range(numCommands):
    steps = int(data[index])
    direction = data[index + 1]
    index += 2

    if direction == 'R':
        newPosition = currentPosition + steps
        intervals.append((currentPosition, newPosition))
        currentPosition = newPosition
    else:
        newPosition = currentPosition - steps
        intervals.append((newPosition, currentPosition))
        currentPosition = newPosition

# intervals 리스트를 정렬합니다.
intervals.sort()

# 구간의 시작과 끝을 기록할 defaultdict
pointCount = defaultdict(int)

# 각 구간의 시작과 끝을 defaultdict에 기록합니다.
for interval in intervals:
    pointCount[interval[0]] += 1
    pointCount[interval[1]] -= 1

overlappedLength = 0
currentOverlap = 0
lastPoint = min(pointCount.keys())

# defaultdict을 순회하며 2번 이상 지나간 구간의 길이를 계산합니다.
for point in sorted(pointCount.keys()):
    if currentOverlap >= 2:
        overlappedLength += point - lastPoint
    currentOverlap += pointCount[point]
    lastPoint = point

print(overlappedLength)