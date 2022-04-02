/**
 * @file methods/ann/loss_functions/mean_squared_error.hpp
 * @author Marcus Edel
 *
 * Definition of the mean squared error performance function.
 *
 * mlpack is free software; you may redistribute it and/or modify it under the
 * terms of the 3-clause BSD license.  You should have received a copy of the
 * 3-clause BSD license along with mlpack.  If not, see
 * http://www.opensource.org/licenses/BSD-3-Clause for more information.
 */
#ifndef MLPACK_METHODS_ANN_LOSS_FUNCTION_MEAN_SQUARED_ERROR_HPP
#define MLPACK_METHODS_ANN_LOSS_FUNCTION_MEAN_SQUARED_ERROR_HPP

#include <mlpack/prereqs.hpp>

namespace mlpack {
namespace ann /** Artificial Neural Network. */ {

/**
 * The mean squared error performance function measures the network's
 * performance according to the mean of squared errors.
 *
 * @tparam MatType Matrix representation to accept as input and use for
 *    computation.
 */
template<typename MatType = arma::mat>
class MeanSquaredErrorType
{
 public:
  /**
   * Create the MeanSquaredErrorType object.
   */
  MeanSquaredErrorType();

  /**
   * Computes the mean squared error function.
   *
   * @param prediction Predictions used for evaluating the specified loss
   *     function.
   * @param target The target vector.
   */
  typename MatType::elem_type Forward(const MatType& prediction,
                                      const MatType& target);

  /**
   * Ordinary feed backward pass of a neural network.
   *
   * @param prediction Predictions used for evaluating the specified loss
   * function
   * @param target The target vector.
   * @param loss The calculated error.
   */
  void Backward(const MatType& prediction,
                const MatType& target,
                MatType& loss);

  /**
   * Serialize the layer
   */
  template<typename Archive>
  void serialize(Archive& ar, const uint32_t /* version */) { }
}; // class MeanSquaredErrorType

typedef MeanSquaredErrorType<arma::mat> MeanSquaredError;

} // namespace ann
} // namespace mlpack

// Include implementation.
#include "mean_squared_error_impl.hpp"

#endif
