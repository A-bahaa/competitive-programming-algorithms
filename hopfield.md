# The Hopfield Network


## What's a hopfield network?

- Unsupervised learning method.
- Hopfield networks are recurrent neural networks create what we call a content-addressable-memory .
- different from the regular computer memory .. more like the human memory.
- They memorize patterns from just one sample. No need for a training set .
- Very much what the brain does. Learning from one shot experiences.
- take a partial or corrupted pattern and reach the most likely completion. 





![Screenshot 2022-11-26 200507](https://user-images.githubusercontent.com/65967989/204102802-f3112832-53d3-4d03-a51f-eaaaae9d90e4.jpg)


https://user-images.githubusercontent.com/65967989/204103428-60c37e26-f735-4bc3-910d-a972cb757785.MP4


## The construction of a hopfield network
- Hopfield net is a set of neurons
- Bidirectionally connected
- symmetric weights, i.e. the weights between all neurons ii and jj are wij=wjiwij=wji.
- Not self-connected, this means that wii=0wii=0.
- Hopfield networks are recurrent
- he inputs of each neuron are the outputs of the others

![Screenshot 2022-11-26 202927](https://user-images.githubusercontent.com/65967989/204103753-7d6bd580-3543-4778-96bf-927dd05c1d3b.jpg)
![Screenshot 2022-11-26 202934](https://user-images.githubusercontent.com/65967989/204103755-2970e27e-6183-4056-8df4-08445abb2cda.jpg)
