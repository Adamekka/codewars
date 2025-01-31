//
//  good-vs-evil.swift
//
//  Copyright © 2025 Adam Cvikl
//

import Foundation

func evaluate(good: String, vsEvil evil: String) -> String {
    let goodWorthArr: [Int] = [1, 2, 3, 3, 4, 10]
    let evilWorthArr: [Int] = [1, 2, 2, 2, 3, 5, 10]

    var goodWorth: Int = 0
    var evilWorth: Int = 0

    for (i, count) in good.split(separator: " ").enumerated() {
        goodWorth += goodWorthArr[i] * Int(count)!
    }

    for (i, count) in evil.split(separator: " ").enumerated() {
        evilWorth += evilWorthArr[i] * Int(count)!
    }

    if goodWorth > evilWorth {
        return "Battle Result: Good triumphs over Evil"
    }

    if goodWorth < evilWorth {
        return "Battle Result: Evil eradicates all trace of Good"
    }

    return "Battle Result: No victor on this battle field"
}
