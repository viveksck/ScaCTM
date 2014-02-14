/*******************************************************************************
    Copyright (c) 2011 Yahoo! Inc. All rights reserved.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License. See accompanying LICENSE file.

    The Initial Developer of the Original Code is Shravan Narayanamurthy.
******************************************************************************/
/*
 * Main_flags_define.h
 *
 * Flags for learntopics
 *
 *  Created on: 19 Jul, 2009
 *      
 */

#ifndef MAIN_FLAGS_DEFINE_H_
#define MAIN_FLAGS_DEFINE_H_

#include "gflags/gflags.h"
#include "constants.h"
#include "tbb/task_scheduler_init.h"

DEFINE_int32(iter,1000,"Number of iterations the topic modeller should be run");
DEFINE_int32(burnin,299,"Number of iterations after which alpha optimization should be to be run after every <optimizestats> iterations");
DEFINE_int32(optimizestats,25,"Optimize hyper parameters every these many iterations");
DEFINE_int32(printloglikelihood,25,"Print log likelihood after every <printlogLikelihood> iterations after burn-in");
DEFINE_int32(topics,100,"The number of topics to be used by LDA.");

//dataflow
DEFINE_string(inputprefix,"lda","The output prefix used for the FormatData routine");
DEFINE_string(dumpprefix,"","The word-topic counts are initialized from this file which is generated by the preprocessing step or at the end of an iteration");

//parameters
DEFINE_int32(subiter,10,"Number of sub-iteration");
DEFINE_bool(restart,false,"Indicates use of failure recovery mode. The iteration to start with should also be specified");
DEFINE_bool(online,false,"Uses online initialization instead of random");
DEFINE_bool(skipiniteta,false,"Don't random initialize eta and lambda, read from topic document. (debug)");
DEFINE_bool(skipinitz,false,"Don't random initialize z, read from topic document. (debug)");
DEFINE_bool(testml,false,"Test Multinomial Logistic (debug)");
DEFINE_int32(startiter,1,"This the iteration at which failure recovery should start");
DEFINE_bool(test,false,"Run the test pipeline. No updates are done & requires an earlier dump of the word-topic counts table");
DEFINE_bool(teststream,false,"Run the test pipeline in streaming mode. Formatting is a part of the pipeline. No updates are done & requires an earlier dump of the word-topic counts table & dictionary");
DEFINE_double(alpha,ALPHA_SUM,"Weight of the Dirichlet conjugate for topics");
DEFINE_double(rho, 1, "Parameter of Normal-Inverse-Wishart prior");
DEFINE_int32(prior, 30, "Kappa and Rho of NIW distribution");
DEFINE_double(beta,BETA,"Weight of the Dirichlet conjugate for words");
DEFINE_int32(chkptinterval,25,"The topic assignments are saved every these many iterations");
DEFINE_int32(lag, -1, "Model data saved every these many iterations.");
DEFINE_string(chkptdir,"","The directory to which the checkpoints need to written");
DEFINE_string(servers,"specify","The set of all memcached servers that are storing the state. E.g. 192.168.0.1, 192.168.0.3:44, 200.132.12.34");
DEFINE_int32(numdumps,1,"Number of word-topic count dumps in the training data");
DEFINE_int32(maxmemory,2048,"The max memory that can be used");
DEFINE_string(dictionary,"specify","The dump of the global dictionary produced in the training run. To be use for teststream");
DEFINE_int32(minibatchsize, 256, "Size of mini batch.");
//hidden
DEFINE_int32(livetokens,500,"Max Live Tokens in pipeline");
DEFINE_int32(model,1,"Unigram-1");
//DEFINE_int32(samplerthreads,tbb::task_scheduler_init::automatic,"The number of foreground threads that run actual LDA pipeline. Default is to figure out automatically");
DEFINE_int32(samplerthreads,12,"The number of foreground threads that run actual LDA pipeline. Default is 12");
DEFINE_int32(pgsamples,1,"Number of Polya-Gamma samples, -1=full sampling");
DEFINE_string(samplemode, "gaussian", "Method for Polya-Gamma sampling, can be precise/pg1/truncated/gaussian");
#endif /* MAIN_FLAGS_DEFINE_H_ */
