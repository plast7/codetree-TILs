import java.util.*
import kotlin.math.*

val sc = Scanner(System.`in`)

fun main() {
    val n = sc.nextInt()
    
    val energy = IntArray(n) // energy[i]: i번 째에서 다음으로 이동할 때 드는 에너지
    for (i in 0..n-2) {
        energy[i] = sc.nextInt()
    }
    val cost = IntArray(n) // cost[i]: i번 째에서 에너지 1을 채울 때 드는 비용
    for (i in 0..n-1) {
        cost[i] = sc.nextInt()
    }

    val L = IntArray(n) // L[i]: 0부터 i번 장소 중, 최소 비용
    L[0] = cost[0]
    for (i in 1..n-1) {
        L[i] = min(L[i - 1], cost[i])
    }

    val result = IntArray(n) // result[i]: i-1에서 i로 이동할 때, '에너지 x 최소 비용'
    for (i in 1..n-1) {
        result[i] = L[i - 1] * energy[i - 1]
    }

    var answer = 0L
    for (i in 0..n-1) {
        answer += result[i]
    }
    print(answer)
}