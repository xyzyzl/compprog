#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+5;

int n, q, c[MAXN];
long long v[MAXN], dp[MAXN];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> q;
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    while(q--)
    {
        long long a, b; cin >> a >> b;
        for(int i = 1; i <= n; i++) dp[i] = -1e15-7; // bar was too high
        int mi1 = 0, mi2 = 0;
        for(int i = 0; i < n; i++)
        {
            dp[c[i]] = max({dp[c[i]], dp[c[i]] + a*v[i], (b*v[i]) + ((mi1 == c[i]) ? dp[mi2] : dp[mi1])});
            if(dp[c[i]] > dp[mi1])
            {
                if(mi1 != c[i])
                    mi2 = mi1;
                mi1 = c[i];
            } else if(dp[c[i]] > dp[mi2] && mi1 != c[i]) // didn't check for repeat equivalence of mi1, mi2
            {
                mi2 = c[i];
            }
        }
        cout << dp[mi1] << endl;
    }
}

/**
 * Hey, did you know that in terms of male human and female Pokémon breeding, Vaporeon
 * is actually not the most compatible Pokémon for humans?
 * This is a common and understandable misconception, however Vaporeon has it's human on Pokémon
 * breedability outclassed by it's cousin evolution, Umbreon.
 * Umbreon weights approximately 60 pounds, or around 27 kilograms, and is 3'3" tall (About a meter), 
 * making it not only large enough to appropriately handle human genitalia, but also light enough to
 * easily be lifted, and promptly set back down repeatedly. 
 * It's relatively small size would also prove a tight entry, which is always a good thing.
 * Umbreon also boasts an extremely impressive defensive stat spread.
 * With it's combination of very high HP, Defense, and Special Defense stats,
 * it can take a great pounding and come back for more! It's ability, Inner Focus,
 * allows it to keep slamming attentively, without getting fatigued. Umbreon also
 * has access to the ability Synchronize, which allows it to share it's current
 * status with you, meaning you will receive all of the pleasure it feels COMBINED with all
 * the pleasure you're getting from pounding this perfect breedable Pokémon. Umbreon also
 * has the capability of seeing perfectly in pitch-black darkness, allowing it to effectively
 * attend a midnight fornication session. Even if you do manage to drain Umbreon's energy with
 * all the furious thrusts, it can recover very quickly with its access to the move Moonlight.
 * Its black fur is also a giant positive attribute, allowing all the excretions you make to
 * be easily seen all over its body. A great fun fact, Umbreon can excrete toxins in its sweat,
 * which would in turn soak into your member and swell it up, making it even more sizable and
 * sensitive. This would not only enhance the experience for you, but for your Umbreon as well
 * (Which with Synchronize, ends up pleasing you exponentially more). Umbreon's wide movepool
 * also supports the hypothesis that Umbreon is the best Pokémon to breed with. It can learn
 * Payback, which doubles in power after the Pokémon is hit, meaning Umbreon with throw it back
 * twice as hard as normally if you're hitting it good. Umbreon can also learn Guard Swap; it could
 * give YOU its insane durability, and go crazy on you all night with your now massive endurance.
 * Speaking of endurance, Umbreon also has access to Endure, making it practically immune to fatigue,
 * it will always have energy left over. Charm is also within Umbreon's movepool, letting it be extremely
 * seductive towards you, easily getting you in the mood. Umbreon can also use Taunt, in turn making you
 * ONLY able to to attacking moves such as Slam, Pound, etc; none of that foreplay shit, right into the
 * action. It also has access to Sleep Talk, giving it the ability to not only give consent in its sleep,
 * allowing access to any of its ports and any time, but also move in it's sleep, making it an effective
 * 24/7 fuckmate. Umbreon still has even more great moves that good to have while smashing, such as Quick
 * Attack, allowing swift slams and bounces, which can have even greater power if Umbreon uses Curse
 * beforehand. Curse would also raise Umbreon's defense, making it able to take powerful thrusting for
 * almost any duration. Looking back, Umbreon's slightly small size ensures a gorilla grip cavity and
 * easy physical manipulation. Its ungodly bulk allows it to take poundings for hours on end and resume
 * after recovering with moonlight (Which works even better when it's sunny). It's access to the abilities
 * Inner Focus and Synchronize allow it to unwaveringly throw it back and add all of its pleasure onto
 * yours, effectively making it twice as amazing as any other Pokémon, or even FOUR TIMES, factoring in
 * the doubled power of payback of course. All of this information in combination with its extremely useful
 * movepool in the world of intercourse makes Umbreon the Pokémon most qualified to breed with humans;
 * able to take dick of any shape, any size, in any position easily for extensive periods of time, while
 * having the ability to return for even more mere seconds later.
 */