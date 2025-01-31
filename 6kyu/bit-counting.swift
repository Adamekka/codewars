//
//  bit-counting.swift
//
//  Copyright © 2025 Adam Cvikl
//

import Foundation

func countBits(_ n: Int) -> Int {
    var n: Int = n
    var result: Int = 0

    for i in sequence(first: pow(2, 32), next: { $0 / 2 }) {
        assert(!i.isNaN)

        let i: Int = .init(truncating: i as NSNumber)

        if i == 0 {
            break
        }

        if i <= n {
            result += 1
            n -= i
        }
    }

    return result
}
