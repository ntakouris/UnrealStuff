#Blu-(sha)Der
BluDer is a dump (I guess you can call it library) for custom material expressions inside UE4. 
Language: HLSL (WORRY. IT WILL NOT BE CROSS COMPILED).

Warning: Some stuff may be outdated or already implemented.

# Hint table

I'm using sublime text 3 and you should use it too. Add this https://github.com/noct/sublime-shaders to packages. It's way better than coding in a textbox...

Unreal doesn't care about input data types

WebGL
=====
vecN -> floatN

fract -> frac

F these *. / .* for floats seriously

mix -> lerp

Be careful of those .xy and .yx

atan(x,y) -> atan2(y,x)

Sometimes people do floatN(x). For a float3 for example you need to convert this to float3(x,x,x)
