import java.util.Scanner
import kotlin.math.max

fun main() {
    val sc = Scanner(System.`in`)

    val n = sc.nextInt()
    val grid = List(n) { List(n) { sc.nextInt() } }
    val dp = List(n) { MutableList(n) { -1 } }

    var result = 0
    for(i in 0 until n) {
        for(j in 0 until n) {
            result = max(result, findMax(i, j, dp, grid, n))
        }
    }

    println(result)
}

fun isAvailable(x: Int, y: Int, n: Int): Boolean {
    return !(x < 0 || y < 0 || x >= n || y >= n)
}

fun findMax(x: Int, y: Int, dp: List<MutableList<Int>>, grid: List<List<Int>>, n: Int): Int {
    if(dp[y][x] != -1) {
        return dp[y][x]
    }

    var ans = 1

    val moveX = listOf(1, 0, -1, 0)
    val moveY = listOf(0, -1, 0, 1)

    for(k in 0 until moveX.size) {
        val nextX = x + moveX[k]
        val nextY = y + moveY[k]

        if (isAvailable(nextX, nextY, n) && grid[nextY][nextX] > grid[y][x]) {
            ans = max(ans, findMax(nextX, nextY, dp, grid, n) + 1)
        }
    }

    dp[y][x] = ans
    return dp[y][x]
}